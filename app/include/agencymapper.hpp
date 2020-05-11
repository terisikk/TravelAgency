#ifndef AGENCYMAPPER_HPP
#define AGENCYMAPPER_HPP

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#include <agency.hpp>

class AgencyMapper {
    
    public:
        AgencyMapper() = default;

        static auto build(std::vector<std::string> data) -> Agency;
        static auto toString(const Agency& agency) -> std::string;
};

#endif
