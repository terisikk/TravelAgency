#ifndef TSV_QUERY_HPP
#define TSV_QUERY_HPP

#include <functional>

namespace tsv {

    template <class T, typename U>
    class Query {
        
        private:
            U compareValue;
            auto (T::* function)() -> U = nullptr;

        public:
            Query<T, U>(U value, auto (T::* func)() -> U) {
                compareValue = value;
                function = func;
            }

            auto execute(T& instance) -> bool { return (instance.*function)() == compareValue; };
    };
} // namespace tsv

#endif
