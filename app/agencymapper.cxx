#include "agencymapper.hpp"

auto AgencyMapper::build(std::vector<std::string> data) -> Agency {

    int ID = std::stoi(data.at(0));
    int staffCount = std::stoi(data.at(3));

    std::stringstream dateStream(data.at(2)); 
    std::tm registeredDate = {};

    dateStream >> std::get_time(&registeredDate, "%Y.%m.%d");

    return Agency(ID, data.at(1), registeredDate, staffCount, data.at(4));
}

auto AgencyMapper::toString(const Agency& agency) -> std::string {
    std::stringstream output;

    const std::tm& time = std::tm(agency.getRegisteredDate());

    output << agency.getID() << "\t\t"
                    << agency.getName() << "\t"
                    << std::put_time(&time, "%Y.%m.%d") << "\t\t"
                    << agency.getStaffCount() << "\t\t\t"
                    << agency.getChiefName() << std::endl;

    return output.str();
}