#ifndef TSV_QUERY_HPP
#define TSV_QUERY_HPP

#include <functional>

namespace tsv {

    template <class T, typename U>
    class Query {
        
        private:
            U compareValue;
            std::function<auto(T&) -> U> function;

        public:
            Query<T, U>(U value, std::function<auto(T&) -> U> func) {
                compareValue = value;
                function = func;
            }

            auto execute(T& instance) -> bool { return function(instance) == compareValue; };
    };
} // namespace tsv

#endif
