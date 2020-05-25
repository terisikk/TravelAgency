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

        auto getID() const -> int { return ID; };
        auto getAgencyID() const -> int { return agencyID; };
        auto getName() const -> std::string { return name; };
        auto getEmploymentDate() const -> std::tm { return employmentDate; };
        auto getCarModel() const -> std::string { return carModel; };
};

#endif