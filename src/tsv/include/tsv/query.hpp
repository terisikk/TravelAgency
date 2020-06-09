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
            explicit Query(std::string key);

        public:
            virtual auto execute(const std::vector<std::string>& instance, const std::vector<std::string>& keys) const -> bool = 0;
            auto getKey() const -> std::string;

    };

namespace query {
    class EQ : public Query {
        private:
            std::string value;

        public:
            explicit EQ(std::string key, std::string value);
            auto execute(const std::vector<std::string>& instance, const std::vector<std::string>& keys) const -> bool override;
    };

    class OR : public Query {
        private:
            Query* query1;
            Query* query2;

        public:
            explicit OR(Query* query1, Query* query2);
            auto execute(const std::vector<std::string>& instance, const std::vector<std::string>& keys) const -> bool override;
    };

    class IN : public Query {
        private:
            std::vector<std::string> values;

        public:
            explicit IN(std::string key, std::vector<std::string> values);
            auto execute(const std::vector<std::string>& instance, const std::vector<std::string>& keys) const -> bool override;

    };

} // namespace query
} // namespace tsv

#endif

