#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <ctime>
#include <string>
#include <utility>

class Driver {
    int ID = 0;
    int agencyID = 0;
    
    std::string name;

    std::tm employmentDate = {};

    std::string carModel;

    public:
        Driver() = default;
        Driver(int ID, int agencyID, std::string name, std::tm employmentDate, std::string carModel)
            : ID(ID), agencyID(agencyID), name(std::move(name)), employmentDate(employmentDate), carModel(std::move(carModel)) {};

        auto getID() -> int { return ID; }; // NOLINT
        auto getAgencyID() -> int { return agencyID; }; // NOLINT
        auto getName() -> std::string { return name; };
        auto getEmplyomentDate() -> std::tm { return employmentDate; };
        auto getCarModel() -> std::string { return carModel; };
};

#endif