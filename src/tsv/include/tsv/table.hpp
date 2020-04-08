#ifndef TSV_TABLE_HPP
#define TSV_TABLE_HPP

#include <iterator>
#include <string>
#include <vector>

namespace tsv {

class Table {
    std::string name = "";
    std::vector<std::string> fieldNames = {};
    std::vector<std::vector<std::string>> rows = {};

    public:
        Table() = default;
        explicit Table(const std::string& name, const std::vector<std::string>& fieldNames);

        auto describe() -> std::string;
        auto insert(const std::vector<std::string>& row) -> bool;
        auto select() -> std::vector<std::vector<std::string>>;
        auto select(const std::vector<std::string>& query) -> std::vector<std::vector<std::string>>;

    private:
        auto filterByFieldValue(const std::vector<std::string>& row, const std::string& field, const std::string& value) -> bool;
};

} // namespace tsv

#endif
