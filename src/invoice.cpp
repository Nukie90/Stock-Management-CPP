#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include "../include/invoice.h"
#include "../include/item.h"
#include "../include/product.h"
#include "../include/service.h"


std::string Invoice::generateHTML() const {
    std::string html;
    html += "<html>\n";
    html += "<head>\n";
    html += "</head>\n";
    html += "<body>\n";
    html += "<h2>Invoice</h2>\n";
    html += "<table>\n";
    html += "<tr>\n";
    html += "<th>Item</th>\n";
    html += "<th>Type</th>\n";
    html += "<th>Price</th>\n";
    html += "<th>Quantity</th>\n";
    html += "<th>Description</th>\n";
    html += "<th>Subtotal</th>\n";
    html += "</tr>\n";

    double total = 0.0;
    for (auto item : items) {
        html += "<tr>\n";
        html += "<td>" + item->getName() + "</td>\n";
        if (Product* product = dynamic_cast<Product*>(item)) {
            html += "<td>Product</td>\n";
            html += "<td>$" + std::to_string(product->getPrice()) + "</td>\n";
            html += "<td>" + std::to_string(product->getQuantity()) + "</td>\n";
            html += "<td></td>\n";
            html += "<td>$" + std::to_string(product->getPrice() * product->getQuantity()) + "</td>\n";
            total += product->getPrice() * product->getQuantity();
        }
        else if (Service* service = dynamic_cast<Service*>(item)) {
            html += "<td>Service</td>\n";
            html += "<td></td>\n";
            html += "<td></td>\n";
            html += "<td>" + service->getDescription() + "</td>\n";
            html += "<td>$" + std::to_string(service->getPrice()) + "</td>\n";
            total += service->getPrice();
        }
        html += "</tr>\n";
    }

    html += "<tr>\n";
    html += "<td colspan=\"5\" style=\"text-align: right;\">Total:</td>\n";
    html += "<td>$" + std::to_string(total)+ "</td>\n";
    html += "</tr>\n";
    html += "</table>\n";
    html += "</body>\n";
    html += "</html>\n";

    return html;
}

void Invoice::saveToFile() const {
    std::ofstream outputFile(fname);
    if (outputFile.is_open()) {
        outputFile << generateHTML();
        outputFile.close();
        std::cout << "Data stored in file: " << fname << std::endl;
    }
    else {
        std::cout << "Error opening file: " << fname << std::endl;
    }
}


std::string Plain_Invoice::generateHTML() const {
    std::string html;
    html += "<html>\n";
    html += "<head>\n";
    html += style;
    html += "</head>\n";
    html += "<body>\n";
    html += "<h2>Invoice</h2>\n";
    html += "<table>\n";
    html += "<tr>\n";
    html += "<th>Item</th>\n";
    html += "<th>Type</th>\n";
    html += "<th>Price</th>\n";
    html += "<th>Quantity</th>\n";
    html += "<th>Description</th>\n";
    html += "<th>Subtotal</th>\n";
    html += "</tr>\n";

    double total = 0.0;
    for (auto item : items) {
        html += "<tr>\n";
        html += "<td>" + item->getName() + "</td>\n";
        if (Product* product = dynamic_cast<Product*>(item)) {
            html += "<td>Product</td>\n";
            std::ostringstream priceStream;
            priceStream << std::fixed << std::setprecision(2) << product->getPrice();
            html += "<td>$" + priceStream.str() + "</td>\n";
            html += "<td>" + std::to_string(product->getQuantity()) + "</td>\n";
            html += "<td></td>\n";
            std::ostringstream subtotalStream;
            subtotalStream << std::fixed << std::setprecision(2) << product->getPrice() * product->getQuantity();
            html += "<td>$" + subtotalStream.str() + "</td>\n";
            total += product->getPrice() * product->getQuantity();
        }
        else if (Service* service = dynamic_cast<Service*>(item)) {
            html += "<td>Service</td>\n";
            html += "<td></td>\n";
            html += "<td></td>\n";
            html += "<td>" + service->getDescription() + "</td>\n";
            std::ostringstream priceStream;
            priceStream << std::fixed << std::setprecision(2) << service->getPrice();
            html += "<td>$" + priceStream.str() + "</td>\n";
            total += service->getPrice();
        }
        html += "</tr>\n";
    }

    html += "<tr>\n";
    html += "<td colspan=\"5\" style=\"text-align: right;\">Total:</td>\n";
    std::ostringstream totalStream;
    totalStream << std::fixed << std::setprecision(2) << total;
    html += "<td>$" + totalStream.str() + "</td>\n";
    html += "</tr>\n";
    html += "</table>\n";
    html += "</body>\n";
    html += "</html>\n";

    return html;
}

    
std::string Decorated_Invoice::generateHTML() const {
    std::string html;
    html += "<html>\n";
    html += "<head>\n";
    html += style;
    html += "</head>\n";
    html += "<body>\n";
    html += "<h2>Invoice</h2>\n";
    html += "<table>\n";
    html += "<tr>\n";
    html += "<th>Item</th>\n";
    html += "<th>Type</th>\n";
    html += "<th>Price</th>\n";
    html += "<th>Quantity</th>\n";
    html += "<th>Description</th>\n";
    html += "<th>Subtotal</th>\n";
    html += "</tr>\n";

    double total = 0.0;
    for (auto item : items) {
        html += "<tr>\n";
        html += "<td>" + item->getName() + "</td>\n";
        if (Product* product = dynamic_cast<Product*>(item)) {
            html += "<td>Product</td>\n";
            std::ostringstream priceStream;
            priceStream << std::fixed << std::setprecision(2) << product->getPrice();
            html += "<td>$" + priceStream.str() + "</td>\n";
            html += "<td>" + std::to_string(product->getQuantity()) + "</td>\n";
            html += "<td></td>\n";
            std::ostringstream subtotalStream;
            subtotalStream << std::fixed << std::setprecision(2) << product->getPrice() * product->getQuantity();
            html += "<td class=\"subtotal\"> $" + subtotalStream.str() + "</td>\n";
            total += product->getPrice() * product->getQuantity();
        }
        else if (Service* service = dynamic_cast<Service*>(item)) {
            html += "<td>Service</td>\n";
            html += "<td></td>\n";
            html += "<td></td>\n";
            html += "<td>" + service->getDescription() + "</td>\n";
            std::ostringstream priceStream;
            priceStream << std::fixed << std::setprecision(2) << service->getPrice();
            html += "<td class=\"service\" >$" + priceStream.str() + "</td>\n";
            total += service->getPrice();
        }
        html += "</tr>\n";
    }

    html += "<tr    class=\"total-row\" >\n";
    html += "<td colspan=\"5\" style=\"text-align: right;\">Total:</td>\n";
    std::ostringstream totalStream;
    totalStream << std::fixed << std::setprecision(2) << total;
    html += "<td>$" + totalStream.str() + "</td>\n";
    html += "</tr>\n";
    html += "</table>\n";
    html += "</body>\n";
    html += "</html>\n";

    return html;
}
