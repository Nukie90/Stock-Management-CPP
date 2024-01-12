#ifndef PRODUCT_H
#define PRODUCT_H

#include "item.h"
#include "iomanip"

// Derived class representing a product
class Product : public Item {
private:
    int quantity;
public:
    Product(const std::string& n, double p, int q) : Item(n, p), quantity(q) {}

    // Overrides the pure virtual function from the base class
    void print(std::ostream& output) const override;
    int getQuantity() const;
    void setQuantity(int q);
    ~Product(){};
};

#endif // PRODUCT_H