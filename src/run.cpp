#include "../include/item.h"
#include "../include/product.h"
#include "../include/service.h"
#include "../include/storage.h"
#include "../include/invoice.h"

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <sstream>
#include <stdexcept>

using namespace std;

//to check that user didn't write decimal number in input
bool isInteger(std::string& input) {
    size_t decimalPos = input.find('.');
    return decimalPos == std::string::npos;
}

void run(int argc, char *argv[]) {
    Invoice* invoice;
    Storage storage;
    int choice;
    std::string itemName, filename, fname, choiceStr, style;
    std::ofstream ofs;
    do {
        std::cout << "1. Add data\n";
        std::cout << "2. Remove data\n";
        std::cout << "3. Edit data\n";
        std::cout << "4. Print\n";
        std::cout << "5. Store data in file\n";
        std::cout << "6. Search data\n";
        std::cout << "7. Load data from file\n";
        std::cout << "8. Display as Graph\n";
        std::cout << "9. Print Invoice\n";
        std::cout << "0. Exit\n";
        std::cout << "\nEnter your choice: ";
        std::cin >> choiceStr;

        try {

            if (!isInteger(choiceStr)) {
            throw std::invalid_argument("Invalid input! Please enter an integer.");
            }
            choice = stoi(choiceStr);

        switch (choice) {
        case 1:
            int itemType;
            std::cout << "1. Product\n";
            std::cout << "2. Service\n";
            std::cout << "Enter item type: ";
            std::cin >> choiceStr;

            try{
                itemType = stoi(choiceStr);
                if (itemType != 1 && itemType != 2) {
                    std::cout << "Invalid input! Enter 1 or 2\n" << std::endl;
                    break;
                }
                std::cout << "Enter item name: ";
                std::cin.ignore();
                getline(std::cin, itemName);

                double itemPrice;
                std::cout << "Enter item price: ";
                std::string priceStr;
                std::cin >> priceStr;

                // Validate item price input
                try{
                size_t pos;
                itemPrice = std::stod(priceStr, &pos);
                if (pos != priceStr.length()) {
                    throw std::invalid_argument("Invalid input! Please enter a valid item price.");
                }
                } catch (const std::invalid_argument& e){
                    std::cout<< "Invalid input! Please enter a valid item price.\n" << std::endl;
                    break;
                }

                if (itemType == 1) {
                    int itemQuantity;
                    std::cout << "Enter item quantity: ";
                    std::string quantityStr;
                    std::cin >> quantityStr;

                    // Validate item quantity input
                    try{
                    size_t pos = 0;
                    itemQuantity = std::stoi(quantityStr, &pos);
                    if (pos != quantityStr.length()) {
                        throw std::invalid_argument("Invalid input! Please enter a valid item quantity.");
                    }else{
                    storage.addItem(new Product(itemName, itemPrice, itemQuantity)); // Create a new Product object and add it to the storage
                    std::cout << "\nItem successfully added" << std::endl;
                    }
                    } catch (const std::invalid_argument& e){
                        std::cout<< "Invalid input! Please enter a valid item quantity.\n" << std::endl;
                        break;
                    }
                }
                else if (itemType == 2) {
                    std::string itemDescription;
                    std::cout << "Enter item description: ";
                    std::cin.ignore();
                    getline(std::cin, itemDescription);

                    storage.addItem(new Service(itemName, itemPrice, itemDescription)); // Create a new Service object and add it to the storage
                    std::cout << "\nService successfully added" << std::endl;
                }
            }
            catch (const std::invalid_argument& e) {
            std::cout << "Invalid input: Enter 1 or 2\n"<< std::endl;
            }
            break;
        case 2:
            std::cout << "Enter item name to remove: ";
            std::cin.ignore();
            getline(std::cin, itemName);

            storage.removeItem(itemName); // Remove an item from the storage
            break;
        case 3:
            std::cout << "Enter item name to edit: ";
            std::cin.ignore();
            getline(std::cin, itemName);

            storage.editItem(itemName); // Edit an item in the storage
            break;
        case 4:
            std::cout << "1. Print to terminal" << std::endl;
            std::cout << "2. Print to File" << std::endl;
            std::cout << "Enter your choice: ";
            
            int c;
            std::cin >> choiceStr;
            std::cin.ignore();  // Ignore the newline character
            try{
                c = stoi(choiceStr);
                if (c != 1 && c != 2) {
                    std::cout << "\nInvalid input! Enter 1 or 2" << std::endl;
                    break;
                }
            
                switch (c)
                {
                case 1:
                    storage.print(std::cout);
                    break;
                case 2:
                    std::cout << "Enter file name: " << std::endl;
                    getline(std::cin, fname);
                    if (fname.empty()) {
                        fname = "Untitled.txt"; // Set default filename as "Untitled.txt"
                    }else{
                        fname +=".txt";
                    }
                    ofs.open(fname);
                    storage.print(ofs);
                    ofs.close();
                    std::cout << "Saved to file " << fname << std::endl;
                    break;        
                default:
                    std::cout << "invalid input";
                    break;
                }
            }catch (const std::invalid_argument& e) {
            std::cout << "Invalid input: Enter 1 or 2\n"<< std::endl;
            }
            break;
        case 5:
            std::cout << "Enter filename to store data: ";
            std::cin.ignore();
            getline(std::cin, filename);
            if (filename.empty()) {
                filename = "Untitled.txt"; // Set default filename as "Untitled.txt"
            }else{
                filename +=".txt";
            }

            storage.storeDataInFile(filename); // Store the data in a file
            std::cout << "\nSaved to "<< filename << std::endl;
            break;
        case 6:
            std::cout << "Enter item name to search: ";
            std::cin.ignore();
            getline(std::cin, itemName);

            storage.searchData(itemName); // Search for an item in the storage
            break;
        case 7:
            std::cout << "Enter the filename: ";
            std::cin.ignore();
            getline(std::cin, fname);
            fname +=".txt";
            storage.loadDataFromFile(fname); // Load data from a file
            break;
        case 8:
            storage.createSVG(argc,argv);
            
            break;
        case 9:
            std::cout << "Enter filename to store invoice: ";
            std::cin.ignore();
            getline(std::cin, filename);
            if (filename.empty()) {
                filename = "Invoice.html"; // Set default filename as "Untitled.txt"
            }else{
                filename +=".html";
            }

            std::cout << "1. No Style Theme: ";
            std::cout << "2. Plain Theme: ";
            std::cout << "3. Dark Theme: ";
            std::cout << "4. Decorated Theme: ";
            std::cout << "\nEnter your choice: ";
            
            cin >> choiceStr;
            try{
                choice = stoi(choiceStr);
                if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
                    throw std::invalid_argument("NUMBER MUST BE BETWEEN 1 TO 4");
                }
                switch (choice)
                {
                case 1:
                    invoice = new Invoice(storage.getItems(), filename);
                    invoice->saveToFile();
                    break;
                case 2:
                    style = "<style>table {  border-collapse: collapse;  width: 100%;}th, td {  text-align: left;  padding: 8px;}th {  background-color: #f2f2f2;}</style>";
                    invoice = new Plain_Invoice(storage.getItems(), filename, style);
                    invoice->saveToFile();           
                    break;
                case 3:
                    style = "<style> html { background-color: black; color: aliceblue;} table {  border-collapse: collapse;  width: 100%;}th, td {  text-align: left;  padding: 8px;}th {  background-color: #321111;}</style>";
                    invoice = new Plain_Invoice(storage.getItems(), filename, style);
                    invoice->saveToFile();           
                    break;
                case 4:
                    style = R"(<style>
                        body {font-family: Arial, sans-serif;margin: 20px;background-color: #f9f9f9;}
                        h2 {text-align: center;color: #333;margin-bottom: 20px;}
                        table {width: 100%;border-collapse: collapse;background-color: #fff;box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);border-radius: 6px;}
                        th, td {padding: 10px;border-bottom: 1px solid #ddd;text-align: left;}
                        th {background-color: #3182ec;font-weight: bold;color: #333;text-shadow: 1px 1px 1px rgba(0, 0, 0, 0.1);}
                        tr:hover {background-color: #f5f5f5;}
                        tr:nth-child(even) {background-color: #f9f9f9;}
                        td:last-child {font-weight: bold;text-align: right;}
                        td:first-child {text-transform: capitalize;}
                        .total-row {background-color: #ffd700;}
                        .total-row td {font-weight: bold;text-align: right;color: #333;}
                        .subtotal {color: #008000;font-weight: bold;}
                        .service {color: #ff0000;font-weight: bold;} </style>)";
                    invoice = new Decorated_Invoice(storage.getItems(), filename, style);
                    invoice->saveToFile();           
                    break;           
                default:
                    cout << "Invalid input" << endl;
                    break;
                }
            }
            catch(const std::invalid_argument& e){
                std::cout << "\nInvalid input! Enter number between 1 to 4" << std::endl;
                choice = -1;
            }
            break;
        case 0:
            std::cout << "\nExiting program...\n";
            break;
        default:
            std::cout << "\nInvalid choice. Try again.\n";
            break;
        }
        std::cout << std::endl;

        } catch (const std::invalid_argument& e) {
            std::cout << "Please enter a whole number!!\n"<< std::endl;
            choice = -1;  // Set choice to an invalid value to trigger the default case in the switch statement
        } catch (const std::out_of_range& e) {
            std::cout <<"Out of range\n"<< std::endl;
            choice = -1;  // Set choice to an invalid value to trigger the default case in the switch statement
        } 
        catch (const std::exception& e) {
            std::cout << "There is error occurs...\n"<< std::endl;
            choice = -1;  // Set choice to an invalid value to trigger the default case in the switch statement
        }
    } while (choice != 0);

}