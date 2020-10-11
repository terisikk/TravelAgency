#include "select_operation_state.hpp"

auto SelectOperationState::getOutput() -> std::string {
    std::stringstream output;
    output << "Enter operation number to execute: " << std::endl;

    for(int i = 0; i < descriptions.size(); i++) {
        output << "  [" << std::to_string(i) <<  "] " << descriptions.at(i) << std::endl; 
    }

    return output.str();
}

auto SelectOperationState::getOutput(const std::string& input) -> std::string {
    int ID = -1;
    
    auto response = std::from_chars(input.data(), input.data()+input.size(), ID);

    if (response.ec == std::errc() && ID >= 0 && ID < states.size()) {
        this->getContext()->transition(states.at(ID));
    }

    return "";
}

auto SelectOperationState::addOperationState(const std::string& description, ui::State* state) -> void {
    descriptions.emplace_back(description);
    states.emplace_back(state);
}
