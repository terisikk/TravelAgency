#ifndef AGENCY_HPP
#define AGENCY_HPP

#include <ctime>
#include <sstream>
#include <string>

class Agency {
    int ID = 0;
    int staffCount = 0;
    std::tm registeredDate = {};

    std::string name;
    std::string chiefName;

    public:
        Agency() = default;
        Agency(int ID, std::string name, std::tm registeredDate, int staffCount, std::string chiefName);

        auto getID() const -> int;
        auto getName() -> std::string;
        auto getRegisteredDate() -> std::tm;
        auto getStaffCount() const -> int;
        auto getChiefName() -> std::string;

};
#endif
