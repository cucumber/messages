#pragma once
// clang-format off
#include "nlohmann/json_fwd.hpp"
#include "nlohmann/json.hpp"
#include <memory>
#include <ostream>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>
#include <optional>
#include <type_traits>


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

    // clang-format on

    template<typename T>
    void to_json(nlohmann::json& json, std::string_view key, const T& opt)
    {
        json[key] = opt;
    }

    template<typename T>
    void to_json(nlohmann::json& json, std::string_view key, const std::optional<T>& opt)
    {
        if (opt.has_value())
        {
            to_json(json, key, *opt);
        }
    }

    template<typename T>
    void from_json(const nlohmann::json& json, std::string_view key, T& opt)
    {

        json.at(key).get_to(opt);
    }

    template<typename T>
    void from_json(const nlohmann::json& json, std::string_view key, std::optional<T>& opt)
    {
        if (json.contains(key))
        {
            from_json(json, key, opt.emplace());
        }
    }
}
