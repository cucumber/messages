#ifndef CUCUMBER_MESSAGES_UTILS_HPP
#define CUCUMBER_MESSAGES_UTILS_HPP

#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <optional>
#include <ostream>
#include <string>
#include <string_view>
#include <vector>

namespace cucumber::messages
{
    std::string camelize(std::string str, bool initial_tail = true);

    template<typename T>
    void to_string(std::ostream& ostream, std::string_view prefix, const T& value)
    {
        ostream << prefix << value;
    }

    template<typename T>
    void to_string(std::ostream& ostream, std::string_view prefix, const std::vector<T>& vector)
    {
        ostream << prefix << '[';

        if (!vector.empty())
        {
            ostream << vector.front();
            for (auto iter = std::next(vector.begin()); iter != vector.end(); ++iter)
            {
                ostream << ", " << *iter;
            }
        }
        ostream << ']';
    }

    template<typename T>
    void to_string(std::ostream& ostream, std::string_view prefix, const std::optional<T>& optional)
    {
        if (optional.has_value())
        {
            to_string(ostream, prefix, *optional);
        }
    }

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

#endif
