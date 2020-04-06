#include "parser.hpp"

const std::string Parser::ITEM_SPLIT_REGEX = "\t";

auto Parser::parseRow(const std::string& input) -> std::vector<std::string> {
    return input.empty() ? 
        std::vector<std::string>() : 
        split(input, ITEM_SPLIT_REGEX);
}

auto Parser::split(const std::string& input, const std::string& regex) -> std::vector<std::string> {
    std::regex re(regex);

    std::sregex_token_iterator first{input.begin(), input.end(), re, -1};
    std::sregex_token_iterator last;

    return {first, last};
}
