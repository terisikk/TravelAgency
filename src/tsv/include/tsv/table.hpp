#ifndef TSV_TABLE_HPP
#define TSV_TABLE_HPP

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
};

} // namespace tsv

#endif
