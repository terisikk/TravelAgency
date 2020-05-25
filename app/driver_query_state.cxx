#include "driver_query_state.hpp"

DriverQueryState::DriverQueryState(tsv::Table* table) {
    this->table = table;
}

auto DriverQueryState::getOutput() -> std::string {
    return "Enter driver name or ID: ";
}

auto DriverQueryState::getOutput(const std::string& input) -> std::string {
    if(table != nullptr) {
        tsv::query::EQ nameQuery("NAME", input);
        tsv::query::EQ idQuery("ID", input);

        tsv::query::OR finalQuery(&nameQuery, &idQuery);

        std::stringstream output;
        output << "ID\tAgency ID\tName\t\tEmplyoment date\t\tCar model" << std::endl;

        for(auto& data : table->select(finalQuery)) {
            output << DriverMapper::toString(DriverMapper::build(data));
        }

        return output.str();
    }

    return "";
}