#include "../include/product.h"
#include "iomanip"

void Product::print(std::ostream& output) const {
    output << std::setw(20) << std::left << name;
    output << std::setw(20) << std::right << "Product";
    output << std::setw(20) << std::right << "$" << std::fixed << std::setprecision(2) << price;
    output << std::setw(20) << std::right << quantity;
    output << std::setw(20) << std::right << "";
    output << std::setw(20) << std::right << "$" << std::fixed << std::setprecision(2) << price * quantity << std::endl;
}

int Product::getQuantity() const { return quantity; }

void Product::setQuantity(int q) { quantity = q; }
