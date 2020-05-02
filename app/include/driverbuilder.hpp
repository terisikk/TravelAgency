#ifndef DRIVERBUILDER_HPP
#define DRIVERBUILDER_HPP

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#include <driver.hpp>

class DriverBuilder {
    
    public:
        DriverBuilder() = default;

        static auto build(std::vector<std::string> data) -> Driver;
};

#endif
