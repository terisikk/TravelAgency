#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include <utility>

class Customer {
    int ID = 0;
    
    std::string name;
    std::string phone;
    std::string address;

    public:
        Customer() = default;
        Customer(int ID, std::string name, std::string phone, std::string address)
            : ID(ID), name(std::move(name)), phone(std::move(phone)), address(std::move(address)) {};

        auto getID() -> int { return ID; }; // NOLINT
        auto getName() -> std::string { return name; };
        auto getPhone() -> std::string { return phone; };
        auto getAddress() -> std::string { return address; };
};

#endif