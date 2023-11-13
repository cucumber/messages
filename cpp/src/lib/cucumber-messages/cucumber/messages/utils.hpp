#pragma once

#include <ostream>
#include <sstream>
#include <string_view>
#include <vector>
#include <optional>

#include <nlohmann/json.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

template <
    typename T
>
struct is_cont {
  static const bool value = false;
};

template <
    typename T,
    typename Alloc
>
struct is_cont<std::vector<T,Alloc> > {
  static const bool value = true;
};


template <
    typename T
>
struct is_optional {
  static const bool value = false;
};

template <
    typename T
>
struct is_optional<std::optional<T> > {
  static const bool value = true;
};

template <
    typename T
>
inline
constexpr bool is_container_v = is_cont<T>::value;

template <
    typename T
>
inline
constexpr bool is_optional_v = is_optional<T>::value;

template <
    typename T,
    typename Callable
>
void
apply_if(const T& v, Callable&& cb)
{
    if constexpr (is_optional_v<T>) {
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

            if constexpr (is_container_v<vtype>) {
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
