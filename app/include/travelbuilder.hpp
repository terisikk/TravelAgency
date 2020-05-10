#ifndef TRAVELBUILDER_HPP
#define TRAVELBUILDER_HPP

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#include <travel.hpp>

class TravelBuilder {
    
    public:
        TravelBuilder() = default;

        static auto build(std::vector<std::string> data) -> Travel;
};

#endif
