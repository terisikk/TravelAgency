#ifndef CUSTOMER_QUERY_STATE_HPP
#define CUSTOMER_QUERY_STATE_HPP

#include <sstream>

#include "customermapper.hpp"
#include "tsv/query.hpp"
#include "tsv/table.hpp"
#include "ui/context.hpp"

class CustomerQueryState : public ui::State {
    private:
        tsv::Table* table = nullptr;

    public:
        explicit CustomerQueryState(tsv::Table* table); 

        auto getOutput() -> std::string override;
        auto getOutput(const std::string& input) -> std::string override;

        auto executeQuery(const std::string& input) -> std::vector<std::vector<std::string>>;
};

#endif
