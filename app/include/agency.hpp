#ifndef AGENCY_HPP
#define AGENCY_HPP

#include <ctime>
#include <string>
#include <utility>

class Agency {
    int ID = 0;
    int staffCount = 0;
    std::tm registeredDate = {};

    std::string name;
    std::string chiefName;

    public:
        Agency() = default;
        Agency(int ID, std::string name, std::tm registeredDate, int staffCount, std::string chiefName) 
            : ID(ID), staffCount(staffCount), registeredDate(registeredDate), name(std::move(name)), chiefName(std::move(chiefName)) {};

        auto getID() const -> int { return ID; };
        auto getName() const -> std::string { return name; };
        auto getRegisteredDate() const -> std::tm { return registeredDate; };
        auto getStaffCount() const -> int { return staffCount; };
        auto getChiefName() const -> std::string { return chiefName; };

};
#endif
