#include "driver_query_state.hpp"

DriverQueryState::DriverQueryState(tsv::Table<Driver>* table) {
    this->table = table;
}

auto DriverQueryState::getOutput() -> std::string {
    return "Enter driver name or ID: ";
}

auto DriverQueryState::getOutput(const std::string& input) -> std::string {
    if(table != nullptr) {
        int queryID = -1;

        try {
            queryID = std::stoi(input);
        } catch(...) {
            queryID = -1;
        }

        tsv::Query<Driver> query([input, queryID](Driver& driver) {return driver.getName() == input || driver.getID() == queryID ;});

        std::stringstream output;
        output << "ID\tAgency ID\tName\t\tEmplyoment date\t\tCar model" << std::endl;

        for(auto& driver : table->select(query)) {
            output << DriverMapper::toString(driver);
        }

        return output.str();
    }

    return "";
}