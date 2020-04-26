#ifndef CUSTOMERBUILDER_HPP
#define CUSTOMERBUILDER_HPP

#include <iomanip>
#include <string>
#include <vector>

#include <customer.hpp>

class CustomerBuilder {
    
    public:
        CustomerBuilder() = default;

        static auto build(std::vector<std::string> data) -> Customer;
};

#endif
