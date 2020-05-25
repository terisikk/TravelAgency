#include "customermapper.hpp"

auto CustomerMapper::build(std::vector<std::string> data) -> Customer {

    int ID = std::stoi(data.at(0));

    return Customer(ID, data.at(1), data.at(2), data.at(3));
}

auto CustomerMapper::toString(const Customer& customer) -> std::string {
    std::stringstream output;

    output << customer.getID() << "\t\t"
                    << customer.getName() << "\t"
                    << customer.getPhone() << "\t"
                    << customer.getAddress() << std::endl;

    return output.str();
}