#ifndef INVOICE_H
#define INVOICE_H

#include <iostream>
#include <string>
#include <vector>
#include "item.h"


class Invoice {
protected:
    std::vector<Item*> items;
    std::string fname;
public:
    Invoice(){};
    Invoice(const std::vector<Item*>& items, const std::string& fname ) : items(items), fname(fname) {}
    virtual ~Invoice(){};
    virtual std::string generateHTML() const;
    void saveToFile() const;
};

class Plain_Invoice : public Invoice {
protected:
    std::string style;
public:
    Plain_Invoice(const std::vector<Item*>& items, const std::string& fname, const std::string& sty) : Invoice(items,fname), style(sty)  {}
    ~Plain_Invoice(){};
    std::string generateHTML() const override;
};

class Decorated_Invoice : public Invoice {
protected:
    std::string style;
public:
    Decorated_Invoice(const std::vector<Item*>& items, const std::string& fname, const std::string& sty) : Invoice(items,fname), style(sty)  {}
    ~Decorated_Invoice(){};
    std::string generateHTML() const override;
};

#endif