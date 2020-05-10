#include "travelbuilder.hpp"

auto TravelBuilder::build(std::vector<std::string> data) -> Travel {

    int ID = std::stoi(data.at(0));
    int driverID = std::stoi(data.at(1));
    int customerID = std::stoi(data.at(3));

    std::stringstream dateStream(data.at(2)); 
    std::tm startTime = {};
    dateStream >> std::get_time(&startTime, "%Y.%m.%d %H:%M");

    std::stringstream moneyStream(data.at(6)); // NOLINT
    long double payment = 0.00;
    moneyStream >> std::get_money(payment);

    return Travel(ID, driverID, startTime, customerID, data.at(4), data.at(5), payment); // NOLINT
}
