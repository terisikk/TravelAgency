#include "agency_query_state.hpp"

AgencyQueryState::AgencyQueryState(tsv::Table<Agency>* table) {
    this->table = table;
}

auto AgencyQueryState::getOutput() -> std::string {
    return "Enter agency name: ";
}

auto AgencyQueryState::getOutput(const std::string& input) -> std::string {
    if(table != nullptr) {
        tsv::Query<Agency, std::string> query(input, &Agency::getName);

        std::stringstream output;
        output << "ID\t\tName\t\tRegistered\t\tStaff count\t\tChief" << std::endl;

        for(auto& agency : table->select(query)) {
            const std::tm& time = std::tm(agency.getRegisteredDate());

            output  << agency.getID() << "\t\t"
                    << agency.getName() << "\t"
                    << std::put_time(&time, "%Y.%m.%d") << "\t\t"
                    << agency.getStaffCount() << "\t\t\t"
                    << agency.getChiefName() << std::endl;
        }

        return output.str();
    }

    return "";
}