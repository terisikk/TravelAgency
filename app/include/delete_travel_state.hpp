#ifndef DELETE_TRAVEL_STATE_HPP
#define DELETE_TRAVEL_STATE_HPP

#include <sstream>

#include "travelmapper.hpp"
#include "tsv/query.hpp"
#include "tsv/table.hpp"
#include "ui/context.hpp"

class DeleteTravelState : public ui::State {
    private:
        tsv::Table* table = nullptr;

    public:
        explicit DeleteTravelState(tsv::Table* table); 

        auto getOutput() -> std::string override;
        auto getOutput(const std::string& input) -> std::string override;
};

#endif
