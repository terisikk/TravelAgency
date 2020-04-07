#ifndef TSV_READER_HPP
#define TSV_READER_HPP

#include <istream>
#include <string>

namespace tsv {

class Reader
{
    public:
        static auto readFile(const std::string& filename) -> std::string;
        static auto readInputStream(std::istream& stream) -> std::string;
};

} // namespace tsv


#endif
