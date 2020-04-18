#ifndef AGENCYBUILDER_HPP
#define AGENCYBUILDER_HPP

#include <iomanip>
#include <string>
#include <vector>

#include <agency.hpp>

class AgencyBuilder {
    
    public:
        AgencyBuilder() = default;

        static auto build(std::vector<std::string> data) -> Agency;
};

#endif
