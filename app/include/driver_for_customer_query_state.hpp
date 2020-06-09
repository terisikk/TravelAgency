#ifndef DRIVER_FOR_CUSTOMER_QUERY_STATE_HPP
#define DRIVER_FOR_CUSTOMER_QUERY_STATE_HPP

#include <ctime>
#include <sstream>

#include "drivermapper.hpp"
#include "travelmapper.hpp"
#include "tsv/query.hpp"
#include "tsv/table.hpp"
#include "ui/context.hpp"

class DriverForCustomerQueryState : public ui::State {
    private:
        tsv::Table* drivers = nullptr;
        tsv::Table* travels = nullptr;

    public:
        explicit DriverForCustomerQueryState(tsv::Table* drivers, tsv::Table* travels); 

        auto getOutput() -> std::string override;
        auto getOutput(const std::string& input) -> std::string override;
};

#endif
