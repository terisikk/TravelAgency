#ifndef CUSTOMERMAPPER_HPP
#define CUSTOMERMAPPER_HPP

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#include <customer.hpp>

class CustomerMapper {
    
    public:
        CustomerMapper() = default;

        static auto build(std::vector<std::string> data) -> Customer;
        static auto toString(const Customer& customer) -> std::string;
};

#endif
