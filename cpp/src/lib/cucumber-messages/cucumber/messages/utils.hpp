#pragma once

#include <ostream>
#include <sstream>
#include <string_view>
#include <vector>
#include <optional>

#include <nlohmann/json.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

namespace detail {

template <
    template <typename> class Container,
    template <typename> class Other,
    typename T
>
std::is_same<Container<T>, Other<T>>
test_is_container(Other<T>*);

template <
    template <typename> class Container,
    typename T
>
std::false_type test_is_container(T*);

} // namespace detail

template <
    template <typename> class C,
    typename T
>
using is_container = decltype(
    detail::test_is_container<C>(static_cast<T*>(nullptr))
);

template <
    template <typename> class C,
    typename T
>
inline
constexpr bool is_container_v = is_container<C, T>::value;

template <
    typename T,
    typename Callable
>
void
apply_if(const T& v, Callable&& cb)
{
    if constexpr (is_container_v<std::optional, T>) {
        if (v) {
            cb(*v);
        }
    } else {
        cb(v);
    }
}

std::string
camelize(std::string s, bool initial_tail = true);

template <typename P, typename T>
void
to_string(std::ostream& os, P&& prefix, T&& opt)
{
    apply_if(
        opt,
        [&](const auto& v) {
            using vtype = std::remove_cvref_t<decltype(v)>;

            if constexpr (is_container_v<std::vector, vtype>) {
                os << prefix << '[';

                for (std::size_t i = 0; i < v.size(); ++i) {
                    os << (i > 0 ? ", " : "") << v[i];
                }

                os << ']';
            } else {
                os << prefix << v;
            }
        }
    );
}

template <typename K, typename T>
void
to_json(json& j, K&& key, T&& opt)
{
    apply_if(
        opt,
        [&](const auto& v) { j[key] = v; }
    );
}

}
