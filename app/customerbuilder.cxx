#include "customerbuilder.hpp"

auto CustomerBuilder::build(std::vector<std::string> data) -> Customer {

    int ID = std::stoi(data.at(0));

    return Customer(ID, data.at(1), data.at(2), data.at(3));
}
