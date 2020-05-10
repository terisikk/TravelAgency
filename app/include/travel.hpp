#ifndef TRAVEL_HPP
#define TRAVEL_HPP

#include <ctime>
#include <string>
#include <utility>

class Travel {
    int ID = 0;
    int driverID = 0;

    std::tm startTime = {};

    int customerID = 0;

    std::string origin;
    std::string destination;

    long double payment = 0.00;

    public:
        Travel() = default;
        Travel(int ID, int driverID, std::tm startTime, int customerID, std::string origin, std::string destination, long double payment)
            : ID(ID), driverID(driverID), startTime(startTime), customerID(customerID), origin(std::move(origin)), destination(std::move(destination)), payment(payment) {};

        auto getID() -> int { return ID; }; // NOLINT
        auto getDriverID() -> int { return driverID; }; // NOLINT
        auto getCustomerID() -> int { return customerID; }; // NOLINT

        auto getStartTime() -> std::tm { return startTime; };
        
        auto getOrigin() -> std::string { return origin; };
        auto getDestination() -> std::string { return destination; };

        auto getPayment() const -> long double { return payment; };
};

#endif