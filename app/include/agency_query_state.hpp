#ifndef AGENCY_QUERY_STATE_HPP
#define AGENCY_QUERY_STATE_HPP

#include <sstream>

#include "agencymapper.hpp"
#include "tsv/query.hpp"
#include "tsv/table.hpp"
#include "ui/context.hpp"

class AgencyQueryState : public ui::State {
    private:
        tsv::Table* table = nullptr;

    public:
        explicit AgencyQueryState(tsv::Table* table); 

        auto getOutput() -> std::string override;
        auto getOutput(const std::string& input) -> std::string override;
};

#endif
