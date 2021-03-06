#ifndef TSV_READER_HPP
#define TSV_READER_HPP

#include <istream>
#include <sstream>
#include <string>
#include <vector>

namespace tsv {

class Reader
{
    public:
        static auto readFile(const std::string& filename) -> std::string;
        static auto readRow(std::istream& stream) -> std::vector<std::string>;
        static auto safeGetLine(std::istream& stream, std::string* line) -> std::istream&;
};

} // namespace tsv


#endif
