#include "tabular_data_parser.hpp"

const std::string TabularDataParser::ITEM_SPLIT_REGEX = "\t";

auto TabularDataParser::parseRow(const std::string& input) -> std::vector<std::string> {
    return split(input, ITEM_SPLIT_REGEX);
}

auto TabularDataParser::split(const std::string& input, const std::string& regex) -> std::vector<std::string> {
    std::regex re(regex);

    std::sregex_token_iterator first{input.begin(), input.end(), re, -1};
    std::sregex_token_iterator last;

    return {first, last};
}