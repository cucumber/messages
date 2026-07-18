#ifndef CUCUMBER_MESSAGES_UTILS_HPP
#define CUCUMBER_MESSAGES_UTILS_HPP

#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <string_view>
#include <vector>

namespace cucumber::messages
{
    // Helper functions to support serializing and deserializing vectors of shared pointers with nlohmann::json
    template<typename T>
    void to_json(nlohmann::json& json, const std::vector<std::shared_ptr<T>>& msg)
    {
        json = nlohmann::json::array();
        for (const auto& item : msg)
        {
            json.push_back(*item);
        }
    }

    template<typename T>
    void from_json(const nlohmann::json& json, std::vector<std::shared_ptr<T>>& msg)
    {
        for (const auto& item : json)
        {
            auto ptr = std::make_shared<T>();
            from_json(item, *ptr);
            msg.push_back(ptr);
        }
    }

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
    void to_string(std::ostream& ostream, std::string_view prefix, const std::shared_ptr<T>& ptr)
    {
        if (ptr != nullptr)
        {
            to_string(ostream, prefix, *ptr);
        }
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
    void to_json(nlohmann::json& json, std::string_view key, const std::shared_ptr<T>& ptr)
    {
        if (ptr != nullptr)
        {
            to_json(json, key, *ptr);
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

    template<typename T>
    void from_json(const nlohmann::json& json, std::string_view key, std::shared_ptr<T>& ptr)
    {
        if (json.contains(key))
        {
            ptr = std::make_shared<T>();
            from_json(json, key, *ptr);
        }
    }
}

#endif
