#include "tsv/reader.hpp"

namespace tsv {

auto Reader::readRow(std::istream& stream) -> std::vector<std::string> {
    std::vector<std::string> items;
    std::string line;
    std::string item;

    safeGetLine(stream, &line);
    std::stringstream rowstream(line);

    while(std::getline(rowstream, item, '\t'))
    {
        items.emplace_back(item);
    }

    return items;
}

// https://stackoverflow.com/questions/6089231/getting-std-ifstream-to-handle-lf-cr-and-crlf
auto Reader::safeGetLine(std::istream& stream, std::string* line) -> std::istream&
{
    line->clear();

    std::istream::sentry se(stream, true);
    std::streambuf* sb = stream.rdbuf();

    for(;;) {
        int c = sb->sbumpc();
        switch (c) {
        case '\n':
            return stream;
        case '\r':
            if(sb->sgetc() == '\n') {
                sb->sbumpc();
            }
            return stream;
        case std::streambuf::traits_type::eof():
            // Also handle the case when the last line has no line ending
            if(line->empty()) {
                stream.setstate(std::ios::eofbit);
            }
            return stream;
        default:
            *line += static_cast<char>(c);
        }
    }
}

} // namespace tsv