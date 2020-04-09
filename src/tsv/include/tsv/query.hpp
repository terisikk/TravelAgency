#ifndef TSV_QUERY_HPP
#define TSV_QUERY_HPP

#include <functional>

namespace tsv {

    template <class T, typename U>
    class Query {

        public:
            explicit Query<T, U>() = default;
            auto execute(T t, std::function<U(T&)> f, U c) -> bool { return f(t) == c; };
    };
} // namespace tsv

#endif
