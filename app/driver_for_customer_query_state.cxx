#include "driver_for_customer_query_state.hpp"

DriverForCustomerQueryState::DriverForCustomerQueryState(tsv::Table* drivers, tsv::Table* travels) {
    this->drivers = drivers;
    this->travels = travels;
}

auto DriverForCustomerQueryState::getOutput() -> std::string {
    return "Enter customer ID: ";
}

auto DriverForCustomerQueryState::getOutput(const std::string& input) -> std::string {
    std::stringstream output;
    output << "ID\tAgency ID\tName\t\tEmplyoment date\t\tCar model" << std::endl;

    for(auto& data : executeQuery(input)) {
        output << DriverMapper::toString(DriverMapper::build(data));
    }

    return output.str();
}

auto DriverForCustomerQueryState::executeQuery(const std::string& input) -> std::vector<std::vector<std::string>> {
    if(drivers != nullptr && travels != nullptr) {
        tsv::query::EQ idQuery("CID", input);

        std::vector<std::string> driverIDs;

        for(auto& data : travels->select(idQuery)) {
            Travel travel = TravelMapper::build(data);
            driverIDs.emplace_back(std::to_string(travel.getDriverID()));
        }

        tsv::query::IN driverQuery("ID", driverIDs);

        return drivers->select(driverQuery, "NAME");
    }
    
    return {};
}