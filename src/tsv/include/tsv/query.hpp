#ifndef TSV_QUERY_HPP
#define TSV_QUERY_HPP

#include <functional>
#include <utility>

namespace tsv {

    template <class T>
    class Query {
        
        private:
            std::function<bool(T&)> function;

        public:
            explicit Query(std::function<bool(T&)> func) {
                function = std::move(func);
            }

            auto execute(T& instance) -> bool { return function(instance); };
    };
} // namespace tsv

#endif
