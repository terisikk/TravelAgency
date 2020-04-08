#include "tsv/table.hpp"

namespace tsv {
    
Table::Table(const std::string& name, const std::vector<std::string>& fieldNames) {
    this->name = name;
    this->fieldNames = fieldNames;
}

auto Table::describe() -> std::string {
    std::string description = name + ":";

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

auto Table::select(const std::vector<std::string>& query) -> std::vector<std::vector<std::string>> {
    std::vector<std::vector<std::string>> result = {};

    for(auto& row : rows) {
        if (filterByFieldValue(row, query.front(), query.back())) {
            result.emplace_back(row);
        }
    }

    return result;
}

auto Table::filterByFieldValue(const std::vector<std::string>& row, const std::string& field, const std::string& value) -> bool {
    auto it = std::find(fieldNames.begin(), fieldNames.end(), field);

    if (it == fieldNames.end()) {
        return {};
    }

    int index = std::distance(fieldNames.begin(), it);
    return row.at(index) == value;
}

} // namespace tsv