#include <utility>

#include <utility>

#include "tsv/query.hpp"

namespace tsv {

Query::Query(std::string key) : key(std::move(key)) {}

auto Query::getKey() const -> std::string { 
    return key;
}


namespace query {

EQ::EQ(std::string key, std::string value) : Query(std::move(key)), value(std::move(value)) {};
            
auto EQ::execute(const std::vector<std::string>& instance, const std::vector<std::string>& keys) const -> bool {
    const auto& it = std::find(keys.begin(), keys.end(), getKey());
    
    if(it != keys.end()) {
        int index = std::distance(keys.begin(), it);
        return instance.at(index) == value;
    }

    return false;
}


OR::OR(Query* query1, Query* query2) : Query(""), query1(query1), query2(query2) {};

auto OR::execute(const std::vector<std::string>& instance, const std::vector<std::string>& keys) const -> bool {
    return query1->execute(instance, keys) || query2->execute(instance, keys);
}


IN::IN(std::string key, std::vector<std::string> values) : Query(std::move(key)), values(std::move(values)) {};

auto IN::execute(const std::vector<std::string>& instance, const std::vector<std::string>& keys) const -> bool {
    const auto& it = std::find(keys.begin(), keys.end(), getKey());
    
    if(it != keys.end()) {
        int index = std::distance(keys.begin(), it);
        return std::find(values.begin(), values.end(), instance.at(index)) != values.end();
    }

    return false;    
}

} // namespace query
} // namespace tsv

