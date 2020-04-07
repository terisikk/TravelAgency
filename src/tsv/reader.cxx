#include "tsv/reader.hpp"

namespace tsv {

auto Reader::readInputStream(std::istream& stream) -> std::string {
    std::string line;
    std::string fullText;

    while (std::getline(stream, line)) {
        fullText += line + '\n';
    }

    return fullText;
}

} // namespace tsv