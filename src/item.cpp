#include "../include/item.h"

std::string Item::getName() const { return name; }

double Item::getPrice() const { return price; }

void Item::setPrice(double x) { price = x; }