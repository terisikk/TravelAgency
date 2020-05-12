#include "driver_query_state.hpp"

DriverQueryState::DriverQueryState(tsv::Table<Driver>* table) {
    this->table = table;
}

auto DriverQueryState::getOutput() -> std::string {
    return "Enter driver name: ";
}

auto DriverQueryState::getOutput(const std::string& input) -> std::string {
    if(table != nullptr) {
        tsv::Query<Driver, std::string> query(input, &Driver::getName);

        std::stringstream output;
        output << "ID\tAgency ID\tName\t\tEmplyoment date\t\tCar model" << std::endl;

        for(auto& driver : table->select(query)) {
            output << DriverMapper::toString(driver);
        }

        return output.str();
    }

    return "";
}