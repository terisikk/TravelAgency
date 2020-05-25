#ifndef TRAVELMAPPER_HPP
#define TRAVELMAPPER_HPP

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#include <travel.hpp>

class TravelMapper {
    
    public:
        TravelMapper() = default;

        static auto build(std::vector<std::string> data) -> Travel;
        static auto toString(const Travel& travel) -> std::string;
};

#endif
