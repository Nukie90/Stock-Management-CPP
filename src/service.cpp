#include "../include/service.h"
#include "fstream"
#include "iomanip"

void Service::print(std::ostream& output) const {
    output << std::setw(20) << std::left << name;
    output << std::setw(20) << std::right << "Service";
    output << std::setw(20) << std::right << "";
    output << std::setw(20) << std::right << "";
    output << std::setw(20) << std::right << description;
    output << std::setw(20) << std::right << "$" << std::fixed << std::setprecision(2) << price << std::endl;
}

std::string Service::getDescription() const { return description; }

void Service::setDescription(const std::string& d) { description = d; }
