#ifndef DRIVERMAPPER_HPP
#define DRIVERMAPPER_HPP

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#include <driver.hpp>

class DriverMapper {
    
    public:
        DriverMapper() = default;

        static auto build(std::vector<std::string> data) -> Driver;
        static auto toString(const Driver& driver) -> std::string;

};

#endif
