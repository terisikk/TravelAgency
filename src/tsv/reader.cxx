#include "tsv/reader.hpp"

namespace tsv {

auto Reader::readRow(std::istream& stream) -> std::vector<std::string> {
    std::vector<std::string> items;
    std::string line;
    std::string item;

    std::getline(stream, line);
    std::stringstream rowstream(line);


    while(std::getline(rowstream, item, '\t'))
    {
        items.emplace_back(item);
    }

    return items;
}

} // namespace tsv