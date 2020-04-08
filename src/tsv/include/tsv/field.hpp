#ifndef TSV_FIELD_HPP
#define TSV_FIELD_HPP

#include <string>

namespace tsv {

    template <class T>
    class Field {

        std::string name;

        public:
            explicit Field<T>(const std::string& name) {
                this->name = name;
            }

            auto getName() -> std::string {
                return name;
            }
    };
} // namespace tsv

#endif
