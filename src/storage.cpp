#include "../include/storage.h"
#include "../include/product.h"
#include "../include/service.h"
#include <stdexcept>
#include <random>
#include <sstream>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSvgWidget>
#include <iomanip>

void Storage::addItem(Item* item) {
    items.push_back(item);
}

void Storage::removeItem(const std::string& itemName) {
    bool trigger = false;
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getName() == itemName) {
            delete *it; // Delete the item object
            items.erase(it); // Remove the item from the vector
            std::cout << "\nItem successfully remove" << std::endl;
            trigger = true;
            break;
        }
    }
    if (!trigger) {
        std::cout << "\nItem not found" << std::endl;
    }
}

void Storage::editItem(const std::string& itemName) {
    bool itemFound = false; // Flag variable to track if the item was found

    for (auto item : items) {
        if (item->getName() == itemName) {
            itemFound = true; // Set the flag to true indicating the item was found
            std::string priceStr, qualityStr;
            if (dynamic_cast<Product*>(item) != nullptr) {
                Product* product = dynamic_cast<Product*>(item);
                
                try{
                    int newPrice;
                    std::cout << "Enter new price: ";
                    std::cin >> priceStr;
                    newPrice = stoi(priceStr);

                    product->setPrice(newPrice); // Modify the price of the product
                    
                    int newQuantity;
                    std::cout << "Enter new quantity: ";
                    std::cin >> qualityStr;
                    newQuantity = stoi(qualityStr);
                    product->setQuantity(newQuantity); // Modify the quantity of the product
                    std::cout << "\nItem successfully edited" << std::endl;
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Please enter a whole number!!\n"<< std::endl;
                }
            }
            else if (dynamic_cast<Service*>(item) != nullptr) {
                Service* service = dynamic_cast<Service*>(item);

                int newPrice;
                std::cout << "Enter new price: ";
                std::cin >> priceStr;
                newPrice = stoi(priceStr);
                service->setPrice(newPrice); // Modify the price of the service
                
                std::string newDescription;
                std::cout << "Enter new description: ";
                std::cin.ignore();
                getline(std::cin, newDescription);
                service->setDescription(newDescription); // Modify the description of the service
                std::cout << "\nItem successfully edited" << std::endl;
            }
            break;
        }
    }
    if (!itemFound){
        std::cout << "\nItem not found" << std::endl;
    }
}

void Storage::print(std::ostream& out) const {
    double total = 0.0;
    out << std::setw(30) << std::right <<"\nInvoice:\n\n";
    out << std::setw(20) << std::left << "Item";
    out << std::setw(20) << std::right << "Type";
    out << std::setw(20) << std::right << "Price";
    out << std::setw(20) << std::right << "Quantity";
    out << std::setw(20) << std::right << "Description";
    out << std::setw(20) << std::right << "Subtotal" << std::endl;
    out << std::setfill('-') << std::setw(130) << "" << std::setfill(' ') << std::endl;
    
    for (auto item : items) {
        item->print(out);
        if (Product* product = dynamic_cast<Product*>(item)) {
            total += product->getPrice() * product->getQuantity();
        }
        else if (Service* service = dynamic_cast<Service*>(item)) {
            total += service->getPrice();
        }
    }
    out << std::setfill('-') << std::setw(130) << "" << std::setfill(' ') << std::endl;
    out << std::setw(40) << std::right << "Total:";
    out << std::setw(20) << std::right << "$" << std::fixed << std::setprecision(2) << total << std::endl;
    out << std::endl;
}

void Storage::storeDataInFile(const std::string& filename) const {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (auto item : items) {
            if (dynamic_cast<Product*>(item) != nullptr) {
                Product* product = dynamic_cast<Product*>(item);
                outputFile << "Product," << product->getName() << "," << product->getPrice() << "," << product->getQuantity() << std::endl;
            }
            else if (dynamic_cast<Service*>(item) != nullptr) {
                Service* service = dynamic_cast<Service*>(item);
                outputFile << "Service," << service->getName() << "," << service->getPrice() << "," << service->getDescription() << std::endl;
            }
        }
        outputFile.close();
        std::cout << "Data stored in file: " << filename << std::endl;
    }
    else {
        std::cout << "Error opening file: " << filename << std::endl;
    }
}

void Storage::searchData(const std::string& itemName) const {
    bool found = false;
    for (auto item : items) {
        if (item->getName() == itemName) {
            std::cout << std::setw(30) << std::right <<"\nInvoice:\n\n";
            std::cout << std::setw(20) << std::left << "Item";
            std::cout << std::setw(20) << std::right << "Type";
            std::cout << std::setw(20) << std::right << "Price";
            std::cout << std::setw(20) << std::right << "Quantity";
            std::cout << std::setw(20) << std::right << "Description";
            std::cout << std::setw(20) << std::right << "Subtotal" << std::endl;
            std::cout << std::setfill('-') << std::setw(130) << "" << std::setfill(' ') << std::endl;
            item->print(std::cout); // Call the print function of the found item
            found = true;
        }
    }
    if (!found) {
        std::cout << "\nItem not found: " << itemName << std::endl;
    }
}

void Storage::loadDataFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::cout << "1. Clear the previous items before opening new data" << std::endl;
        std::cout << "2. Sum up items with new data" << std::endl;
        std::cout << "Enter your choice: ";
        std::string choice;
        int clear_content;
        std::cin >> choice;

        clear_content = stoi(choice);
        if (clear_content != 1 && clear_content != 2) {
            std::cout << "\nInvalid input! Enter 1 or 2" << std::endl;
            return;
        }

        switch (clear_content) {
            case 1:
                items.clear(); // Clear the existing items in the storage
                break;
            case 2:
                break; // Continue without clearing existing items
            default:
                std::cout << "\nInvalid choice! Enter 1 or 2" << std::endl;
                return;
        }

        std::string line;
        while (getline(inputFile, line)) {
            std::string itemType, itemName;
            double itemPrice;

            std::stringstream ss(line);
            getline(ss, itemType, ',');
            getline(ss, itemName, ',');
            ss >> itemPrice;

            if (itemType == "Product") {
                int itemQuantity;
                ss.ignore();  // Ignore the comma before itemQuantity
                ss >> itemQuantity;

                // Check if an item with the same name already exists
                bool itemExists = false;
                for (auto item : items) {
                    if (item->getName() == itemName && dynamic_cast<Product*>(item) != nullptr) {
                        Product* product = dynamic_cast<Product*>(item);
                        // Sum up quantity for the existing item
                        product->setQuantity(product->getQuantity() + itemQuantity);
                        itemExists = true;
                        break;
                    }
                }
                if (!itemExists) {
                    addItem(new Product(itemName, itemPrice, itemQuantity));
                }
            }
            else if (itemType == "Service") {
                std::string itemDescription;
                ss.ignore();  // Ignore the comma before itemDescription
                getline(ss, itemDescription);

                // Check if an item with the same name already exists
                bool itemExists = false;
                for (auto item : items) {
                    if (item->getName() == itemName && dynamic_cast<Service*>(item) != nullptr) {
                        Service* service = dynamic_cast<Service*>(item);
                        // Ignore updating the quantity for Service items
                        itemExists = true;
                        break;
                    }
                }
                if (!itemExists) {
                    addItem(new Service(itemName, itemPrice, itemDescription));
                }
            }
        }
        inputFile.close();
        print(std::cout);
        std::cout << "Data loaded from file: " << filename << std::endl;
    }
    else {
        std::cout << "Error opening file: " << filename << std::endl;
    }
}

void Storage::graphfromSVG(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget* widget = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout(widget);
    QSvgWidget* svgWidget = new QSvgWidget("graph.svg");
    layout->addWidget(svgWidget);
    std::cout<< "Graph generated" << std::endl;
    widget->show();
    app.exec();
}


void Storage::createSVG(int argc, char *argv[]) {
    // Calculate the maximum value for the y-axis
    double maxY = 0.0;
    for (auto item : items) {
        if (Product* product = dynamic_cast<Product*>(item)) {
            double subtotal = product->getPrice() * product->getQuantity();
            if (subtotal > maxY) {
                maxY = subtotal;
            }
        }
        else if (Service* service = dynamic_cast<Service*>(item)) {
            double price = service->getPrice();
            if (price > maxY) {
                maxY = price;
            }
        }
    }

    // Set up SVG parameters
    int width = 1000;
    int height = 750;
    int margin = 50;
    int graphHeight = height - 2 * margin;
    int graphWidth = width - 2 * margin;

    // Open the SVG file for writing
   std::ofstream svgFile("graph.svg");
    if (!svgFile.is_open()) {
        std::cout << "Error opening SVG file." << std::endl;
        return;
    }

    // Write the SVG header
    svgFile << "<?xml version=\"1.0\" standalone=\"no\"?>" << std::endl;
    svgFile << "<svg width=\"" << width << "\" height=\"" << height << "\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">" << std::endl;

    // Draw the x-axis
    svgFile << "<line x1=\"" << margin << "\" y1=\"" << height - margin << "\" x2=\"" << width - margin << "\" y2=\"" << height - margin << "\" stroke=\"black\" stroke-width=\"2\" />" << std::endl;

    // Draw the y-axis
    svgFile << "<line x1=\"" << margin << "\" y1=\"" << margin << "\" x2=\"" << margin << "\" y2=\"" << height - margin << "\" stroke=\"black\" stroke-width=\"2\" />" << std::endl;

    // Write the labels for x and y axes
    svgFile << "<text x=\"" << width / 2 << "\" y=\"" << height - 5 << "\" font-family=\"Arial\" font-size=\"12\" text-anchor=\"middle\">Total Sales</text>" << std::endl;
    svgFile << "<text transform=\"rotate(-90)\" x=\"-" << height / 2 << "\" y=\"" << 20 << "\" font-family=\"Arial\" font-size=\"12\" text-anchor=\"middle\">Item</text>" << std::endl;

    // Calculate the x-axis scale
    int numItems = items.size();
    int barWidth = graphWidth / numItems;
    double scaleFactor = graphHeight / maxY;

    // Draw the bars for each item
    int x = margin;
    for (auto item : items) {
        double barHeight = 0.0;
        double value = 0.0;
        if (Product* product = dynamic_cast<Product*>(item)) {
            barHeight = product->getPrice() * product->getQuantity() * scaleFactor;
        }
        else if (Service* service = dynamic_cast<Service*>(item)) {
            barHeight = service->getPrice() * scaleFactor;
        }
        // Generate a random color for the bar
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, 255);
        int r = dis(gen);
        int g = dis(gen);
        int b = dis(gen);
        std::stringstream colorStream;
        colorStream << "rgb(" << r << "," << g << "," << b << ")";
        std::string color = colorStream.str();

        // Adjust the bar height to create space for labels
        double adjustedBarHeight = barHeight - 10;

        // Label the bar with its value
        double itemValue = item->getPrice();
        svgFile << "<text x=\"" << x + barWidth / 2 << "\" y=\"" << height - margin - adjustedBarHeight - 5 << "\" font-family=\"Arial\" font-size=\"10\" text-anchor=\"middle\"> $" << itemValue << " each</text>" << std::endl;

        // Draw the bar
        svgFile << "<rect x=\"" << x << "\" y=\"" << height - margin - adjustedBarHeight << "\" width=\"" << barWidth - 10 << "\" height=\"" << adjustedBarHeight << "\" fill=\"" << color << "\" />" << std::endl;
        
        // Label the bar with its value
        std::string valueLabel = std::to_string(static_cast<int>(barHeight / scaleFactor));
        
        // Adjust the y-position of the value label based on the available space
        double valueLabelY = height - margin + 30;
        if (adjustedBarHeight < 20) {
            valueLabelY = height - margin - adjustedBarHeight - 15;
        }
        svgFile << "<text x=\"" << x + barWidth / 2 << "\" y=\"" << valueLabelY << "\" font-family=\"Arial\" font-size=\"10\" text-anchor=\"middle\">$" << valueLabel << " Total</text>" << std::endl;

        // Label the bar with its item name
        std::string itemName = item->getName();
        
        // Adjust the y-position of the item name label based on the available space
        double itemNameY = height - margin + 15;
        if (adjustedBarHeight < 20) {
            itemNameY = height - margin - adjustedBarHeight - 25;
        }
        svgFile << "<text x=\"" << x + barWidth / 2 << "\" y=\"" << itemNameY << "\" font-family=\"Arial\" font-size=\"12\" text-anchor=\"middle\">" << itemName << "</text>" << std::endl;

        x += barWidth;
    }

    // Write the SVG footer
    svgFile << "</svg>" << std::endl;

    svgFile.close();

    graphfromSVG(argc,argv);
}