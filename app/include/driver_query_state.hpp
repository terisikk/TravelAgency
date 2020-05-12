#ifndef DRIVER_QUERY_STATE_HPP
#define DRIVER_QUERY_STATE_HPP


#include <ctime>
#include <sstream>

#include "drivermapper.hpp"
#include "tsv/query.hpp"
#include "tsv/table.hpp"
#include "ui/context.hpp"

class DriverQueryState : public ui::State {
    private:
        tsv::Table<Driver>* table = nullptr;

    public:
        explicit DriverQueryState(tsv::Table<Driver>* table); 

        auto getOutput() -> std::string override;
        auto getOutput(const std::string& input) -> std::string override;
};

#endif
