#ifndef SERVICE_H
#define SERVICE_H

#include "item.h"
#include "fstream"
#include "iomanip"

// Derived class representing a service
class Service : public Item {
private:
    std::string description;

public:
    Service(const std::string& n, double p, const std::string& d) : Item(n, p), description(d) {}
    
    // Overrides the pure virtual function from the base class
    void print(std::ostream& output) const override;
    std::string getDescription() const;
    void setDescription(const std::string& d);
    ~Service(){};
};

#endif // SERVICE_H
