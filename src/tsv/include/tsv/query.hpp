#ifndef TSV_QUERY_HPP
#define TSV_QUERY_HPP

#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace tsv {

    class Query {
        std::string key;

        protected:
            explicit Query(std::string key) : key(std::move(key)) {};

        public:
            virtual auto execute(const std::vector<std::string>& instance, const std::vector<std::string>& keys) const -> bool = 0;

            auto getKey() const -> std::string { return key;}

    };

namespace query {
    class EQ : public Query {
        private:
            std::string value;

        public:
            explicit EQ(std::string key, std::string value) : Query(std::move(key)), value(std::move(value)) {};
            
            auto execute(const std::vector<std::string>& instance, const std::vector<std::string>& keys) const -> bool override {
                const auto& it = std::find(keys.begin(), keys.end(), getKey());
                
                if(it != keys.end()) {
                    int index = std::distance(keys.begin(), it);
                    return instance.at(index) == value;
                }

                return false;
            }
    };

    class OR : public Query {
        private:
            Query* query1;
            Query* query2;

        public:
            explicit OR(Query* query1, Query* query2) : Query(""), query1(query1), query2(query2) {};

            auto execute(const std::vector<std::string>& instance, const std::vector<std::string>& keys) const -> bool override {
                return query1->execute(instance, keys) || query2->execute(instance, keys);
            }
    };

} // namespace query
} // namespace tsv

#endif

