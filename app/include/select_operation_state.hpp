#ifndef SELECT_OPERATION_STATE_HPP
#define SELECT_OPERATION_STATE_HPP

#include <charconv>
#include <sstream>
#include <string>
#include <vector>

#include "ui/context.hpp"

class SelectOperationState : public ui::State {
    private:
        std::vector<ui::State*> states = {};
        std::vector<std::string> descriptions = {};

    public:
        explicit SelectOperationState() = default;

        auto getOutput() -> std::string override;
        auto getOutput(const std::string& input) -> std::string override;

        auto addOperationState(const std::string& description, ui::State* state) -> void;
};

#endif
