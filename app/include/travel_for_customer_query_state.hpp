#ifndef TRAVEL_FOR_CUSTOMER_QUERY_STATE_HPP
#define TRAVEL_FOR_CUSTOMER_QUERY_STATE_HPP

#include <sstream>
#include <vector>

#include "travelmapper.hpp"
#include "tsv/query.hpp"
#include "tsv/table.hpp"
#include "ui/context.hpp"

class TravelForCustomerQueryState : public ui::State {
    private:
        tsv::Table* table = nullptr;

    public:
        explicit TravelForCustomerQueryState(tsv::Table* table); 

        auto getOutput() -> std::string override;
        auto getOutput(const std::string& input) -> std::string override;
};

#endif
