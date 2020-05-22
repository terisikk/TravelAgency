#ifndef TSV_TABLE_HPP
#define TSV_TABLE_HPP

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "tsv/query.hpp"
#include "tsv/reader.hpp"

namespace tsv {

class Table {
    std::vector<std::string> keys;
    std::vector<std::vector<std::string>> rows = {};

    public:
        explicit Table(std::vector<std::string> keys) {
            this->keys = std::move(keys);
        }

        auto insert(const std::vector<std::string>& item) -> bool { 
            if(!item.empty() && item.size() == keys.size()) {
                rows.emplace_back(item); 
                return true;
            }   
            return false; 
        };

        auto select() -> std::vector<std::vector<std::string>> { 
            std::vector<std::vector<std::string>> result;
            result = rows; 
            return result;
        };
        
        auto select(const std::string& orderBy) -> std::vector<std::vector<std::string>> {
            std::vector<std::vector<std::string>> result;
            result = rows;

            const auto& it = std::find(keys.begin(), keys.end(), orderBy);
            int index = 0;

            if(it != keys.end()) {
                index = std::distance(keys.begin(), it);
            }

            auto comp = [index](std::vector<std::string> first, std::vector<std::string> second) { return first.at(index) < second.at(index);};

            std::sort(result.begin(), result.end(), comp);

            return result;
        }

        auto select(const Query& query) -> std::vector<std::vector<std::string>> { 
            std::vector<std::vector<std::string>> result;

            for (const auto &row : rows) {
                if (query.execute(row, keys)) {
                    result.emplace_back(row);
                }
            }

            return result;
        };

        auto populate(const std::string& filename) -> void {
            std::ifstream ifs;
            ifs.open(filename, std::ios_base::in);

            while(!ifs.eof()) {
                std::vector<std::string> items = tsv::Reader::readRow(ifs);
                if(!items.empty()) {
                    this->insert(items);
                }
            }
        }
};

} // namespace tsv

#endif
