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

        auto getID() const -> int { return ID; };
        auto getDriverID() const -> int { return driverID; };
        auto getCustomerID() const -> int { return customerID; };

        auto getStartTime() const -> std::tm { return startTime; };
        
        auto getOrigin() const -> std::string { return origin; };
        auto getDestination() const -> std::string { return destination; };

        auto getPayment() const -> long double { return payment; };
};

#endif