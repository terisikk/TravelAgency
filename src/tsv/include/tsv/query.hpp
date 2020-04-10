#ifndef TSV_QUERY_HPP
#define TSV_QUERY_HPP

#include <functional>

namespace tsv {

    template <class T>
    class Query {

        public:
            explicit Query<T>() = default;

            template<typename U>
            auto execute(U value, T instance, auto (T::* function)() -> decltype(value)) -> bool { return (instance.*function)() == value; };
    };
} // namespace tsv

#endif
