#ifndef TABULAR_DATA_PARSER_HPP
#define TABULAR_DATA_PARSER_HPP

#include <regex>
#include <string>
#include <vector>

class TabularDataParser
{
    public:
        static const std::string ITEM_SPLIT_REGEX;
        static auto parseRow(const std::string& /*input*/) -> std::vector<std::string>;

    private:
        static auto split(const std::string& input, const std::string& regex) -> std::vector<std::string>;
};

#endif
