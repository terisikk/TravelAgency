#include "agencybuilder.hpp"

auto AgencyBuilder::build(std::vector<std::string> data) -> Agency {

    int ID = std::stoi(data.at(0));
    int staffCount = std::stoi(data.at(3));

    std::stringstream dateStream(data.at(2)); 
    std::tm registeredDate = {};

    dateStream >> std::get_time(&registeredDate, "%Y.%m.%d");

    return Agency(ID, data.at(1), registeredDate, staffCount, data.at(4));
}
