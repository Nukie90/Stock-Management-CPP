
#ifndef STORAGE_H
#define STORAGE_H

#include "item.h"
#include <iostream>
#include <string>
#include <vector>

// Class representing the storage system
class Storage {
private:
    std::vector<Item*> items; // Vector to store pointers to items
public:
    virtual ~Storage() {
        for (auto item : items) {
            delete item; // Delete all item objects
        }
        items.clear(); // Clear the vector
    }
    std::vector<Item*> getItems(){return items;};
    void addItem(Item* item);
    void removeItem(const std::string& itemName);
    void editItem(const std::string& itemName);
    void print(std::ostream& out) const;
    void storeDataInFile(const std::string& filename) const;
    void searchData(const std::string& itemName) const;
    void loadDataFromFile(const std::string& filename);
    void graphfromSVG(int argc, char *argv[]);
    void createSVG(int argc, char *argv[]);
};


#endif