#ifndef INSERT_TRAVEL_STATE_HPP
#define INSERT_TRAVEL_STATE_HPP

#include <sstream>

#include "travelmapper.hpp"
#include "tsv/query.hpp"
#include "tsv/table.hpp"
#include "ui/context.hpp"

class InsertTravelState : public ui::State {
    private:
        tsv::Table* table = nullptr;

    public:
        explicit InsertTravelState(tsv::Table* table); 

        auto getOutput() -> std::string override;
        auto getOutput(const std::string& input) -> std::string override;
};

#endif
