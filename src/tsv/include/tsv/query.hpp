#ifndef TSV_QUERY_HPP
#define TSV_QUERY_HPP

#include <utility>

namespace tsv {

    class Query {
        std::string key;

        public:
            explicit Query(std::string key) : key(std::move(key)) {};
            virtual auto execute(const std::vector<std::string>& instance, std::vector<std::string> keys) const -> bool = 0;

            auto getKey() const -> std::string { return key;}

    };

namespace query {
    class EQ : public Query {
        private:
            std::string value;

        public:
            explicit EQ(std::string key, std::string value) : Query(std::move(key)), value(std::move(value)) {};
            auto execute(const std::vector<std::string>& instance, std::vector<std::string> keys) const -> bool override {
                const auto& it = std::find(keys.begin(), keys.end(), getKey());
                
                if(it != keys.end()) {
                    int index = std::distance(keys.begin(), it);
                    return instance[index] == value;
                }

                return false;
            }
    };

    class OR : public Query {
        private:
            Query query1;
            Query query2;

        public:
            explicit OR(Query query1, Query query2) : Query("") {};

            auto execute(const std::vector<std::string>& instance, std::vector<std::string> keys) const -> bool override {
                return query1.execute(instance, keys) || query2.execute(instance, keys);
            }
    }

} // namespace query
} // namespace tsv

#endif

