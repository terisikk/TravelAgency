#include "insert_travel_state.hpp"

InsertTravelState::InsertTravelState(tsv::Table* table) {
    this->table = table;
}

auto InsertTravelState::getOutput() -> std::string {
    return "Enter the following details:\nTravel ID: ";
}

auto InsertTravelState::getOutput(const std::string& input) -> std::string {

    std::vector<std::string> prompts = {"Driver ID: ", 
                                        "Travel start time (YYYY.MM.DD hh:mm): ", 
                                        "Customer ID: ", 
                                        "Travel origin: ", 
                                        "Travel destination: ", 
                                        "Payment: "};

    std::vector<std::string> data = {input};

    //std::cin.imbue(std::locale("en_US.UTF-8"));

    for(auto& prompt : prompts) {
        std::string input;
        
        std::cout << prompt;
        std::getline(std::cin, input);
        
        data.emplace_back(input);
    }

    try {
        Travel travel = TravelMapper::build(data);
    } catch (...) {
        return "Error validating data!\n";
    }

    if(table != nullptr) {
        table->insert(data);
        return "Travel inserted!\n";
    }

    return "";
}
