#include "tsv/table.hpp"

namespace tsv {
    
Table::Table(const std::string& name, const std::vector<std::string>& fieldNames) {
    this->name = name;
    this->fieldNames = fieldNames;
}

auto Table::describe() -> std::string {
    std::string description = this->name + ":";

    for(const auto& item : fieldNames) {
        description += " " + item;
    }

    return description;
}

auto Table::insert(const std::vector<std::string>& row) -> bool {
    rows.emplace_back(row);
    return true;
}

auto Table::select() -> std::vector<std::vector<std::string>> {
    return rows;
}

} // namespace tsv