#ifndef TSV_TABLE_HPP
#define TSV_TABLE_HPP

#include <fstream>
#include <functional> 
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "tsv/query.hpp"
#include "tsv/reader.hpp"

namespace tsv {

template<class T>
class Table {
    std::string name = "";
    std::vector<T> rows = {};

    public:
        Table() = default;
        explicit Table<T>(const std::string& name) { this->name = name; };

        auto insert(T& item) -> bool { rows.emplace_back(item); return true; };
        auto select() -> std::vector<T> { return rows; };
        
        template<typename U>
        auto select(Query<T, U>& query) -> std::vector<T> { 
            std::vector<T> result = {};

            std::copy_if(rows.begin(), rows.end(), std::back_inserter(result), [&query](T row) { return query.execute(row);});

            return result;
        };

        auto populate(const std::string& filename, std::function<auto(std::vector<std::string>) -> T> builderFunction) -> void {
            std::ifstream ifs;
            ifs.open(filename, std::ios_base::in);

            while(!ifs.eof()) {
                std::vector<std::string> items = tsv::Reader::readRow(ifs);
                if(!items.empty()) {
                    T construct = builderFunction(items);
                    this->insert(construct);
                }
            }
        }
};

} // namespace tsv

#endif
