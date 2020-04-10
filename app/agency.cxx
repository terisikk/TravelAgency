#include <utility>

#include "agency.hpp"

Agency::Agency(std::string ID, std::string name, std::string registeredDate, std::string staffCount, std::string chiefName) {
    this->ID = std::move(ID);
    this->name = std::move(name);
    this->registeredDate = std::move(registeredDate);
    this->staffCount = std::move(staffCount);
    this->chiefName = std::move(chiefName);
}

auto Agency::getID() -> std::string {
    return ID;
}

auto Agency::getName() -> std::string {
    return name;
}

auto Agency::getRegisteredDate() -> std::string {
    return registeredDate;
}

auto Agency::getStaffCount() -> std::string {
    return staffCount;
}

auto Agency::getChiefName() -> std::string {
    return chiefName;
}
