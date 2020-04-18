#include <utility>

#include "agency.hpp"

Agency::Agency(int ID, std::string name, std::tm registeredDate, int staffCount, std::string chiefName) {
    this->ID = ID;
    this->name = std::move(name);
    this->registeredDate = registeredDate;
    this->staffCount = staffCount;
    this->chiefName = std::move(chiefName);
}

auto Agency::getID() const -> int {
    return ID;
}

auto Agency::getName() -> std::string {
    return name;
}

auto Agency::getRegisteredDate() -> std::tm {
    return registeredDate;
}

auto Agency::getStaffCount() const -> int  {
    return staffCount;
}

auto Agency::getChiefName() -> std::string {
    return chiefName;
}
