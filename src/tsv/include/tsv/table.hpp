#ifndef TSV_TABLE_HPP
#define TSV_TABLE_HPP

#include <iterator>
#include <string>
#include <vector>

#include "tsv/query.hpp"

namespace tsv {

template<class T>
class Table {
    std::string name = "";
    std::vector<T> rows = {};

    public:
        Table<T>() = default;
        explicit Table<T>(const std::string& name) { this->name = name; };

        auto insert(T& item) -> bool { rows.emplace_back(item); return true; };
        auto select() -> std::vector<T> { return rows; };
        
        template<typename U>
        auto select(Query<T, U>& query) -> std::vector<T> { 
            std::vector<T> result = {};

            std::copy_if(rows.begin(), rows.end(), std::back_inserter(result), [&query](T row) { return query.execute(row);});

            return result;
        };
};

} // namespace tsv

#endif
