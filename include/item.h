#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

// Abstract base class representing an item
class Item {
protected:
    std::string name;
    double price;
public:
    Item(const std::string& n, double p) : name(n), price(p) {}
    // Pure virtual function (makes Item an abstract class)
    virtual void print(std::ostream& output) const = 0;
    std::string getName() const;
    double getPrice() const;
    void setPrice(double x);
    virtual ~Item(){};
};

#endif // ITEM_H
