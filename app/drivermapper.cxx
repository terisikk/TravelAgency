#include "drivermapper.hpp"

auto DriverMapper::build(std::vector<std::string> data) -> Driver {

    int ID = std::stoi(data.at(0));
    int agencyID = std::stoi(data.at(1));

    std::stringstream dateStream(data.at(3)); 
    std::tm employmentDate = {};

    dateStream >> std::get_time(&employmentDate, "%Y.%m.%d");

    return Driver(ID, agencyID, data.at(2), employmentDate, data.at(4));
}

auto DriverMapper::toString(const Driver& driver) -> std::string {
    std::stringstream output;

    const std::tm& time = std::tm(driver.getEmploymentDate());

    output << driver.getID() << "\t"
                    << driver.getAgencyID() << "\t\t"
                    << driver.getName() << "\t"
                    << std::put_time(&time, "%Y.%m.%d") << "\t\t"
                    << driver.getCarModel() << std::endl;

    return output.str();
}