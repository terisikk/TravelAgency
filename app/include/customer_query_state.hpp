#ifndef CUSTOMER_QUERY_STATE_HPP
#define CUSTOMER_QUERY_STATE_HPP

#include <sstream>

#include "customermapper.hpp"
#include "tsv/query.hpp"
#include "tsv/table.hpp"
#include "ui/context.hpp"

class CustomerQueryState : public ui::State {
    private:
        tsv::Table<Customer>* table = nullptr;

    public:
        explicit CustomerQueryState(tsv::Table<Customer>* table); 

        auto getOutput() -> std::string override;
        auto getOutput(const std::string& input) -> std::string override;
};

#endif
