#pragma once

#include <ostream>
#include <sstream>
#include <string_view>
#include <vector>
#include <optional>
#include <type_traits>

#include <nlohmann/json.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

template <
    typename T,
    template <typename...> typename Primary
>
struct is_specialization_of : std::false_type {};

template <
    template <typename...> typename Primary,
    typename... Args
>
struct is_specialization_of<Primary<Args...>, Primary> : std::true_type {};

template <
    typename T,
    template <typename...> class Primary
>
using
is_specialization_of_t = is_specialization_of<T, Primary>;

template <
    typename T,
    template <typename...> class Primary
>
inline
constexpr bool
is_specialization_of_v = is_specialization_of_t<T, Primary>::value;

template <
    typename T,
    typename Callable
>
void
apply_if(const T& v, Callable&& cb)
{
    if constexpr (is_specialization_of_v<T, std::optional>) {
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
            using vtype = std::decay_t<decltype(v)>;

            if constexpr (is_specialization_of_v<vtype, std::vector>) {
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
        [&](const auto& v) {
            using vtype = std::decay_t<decltype(v)>;

            if constexpr (std::is_enum_v<vtype>) {
                j[key] = to_string(v);
            } else {
                j[key] = v;
            }
        }
    );
}

}
