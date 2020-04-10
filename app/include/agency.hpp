#ifndef AGENCY_HPP
#define AGENCY_HPP

#include <string>

class Agency {
    std::string ID;
    std::string name;
    std::string registeredDate;
    std::string staffCount;
    std::string chiefName;

    public:
        Agency() = default;
        Agency(std::string ID, std::string name, std::string registeredDate, std::string staffCount, std::string chiefName);

        auto getID() -> std::string;
        auto getName() -> std::string;
        auto getRegisteredDate() -> std::string;
        auto getStaffCount() -> std::string;
        auto getChiefName() -> std::string;

};
#endif
