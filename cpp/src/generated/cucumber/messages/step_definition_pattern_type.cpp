#include "cucumber/messages/step_definition_pattern_type.hpp"
#include "nlohmann/json.hpp"
#include <iostream>
#include <string_view>
#include <unordered_map>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    std::string_view to_string(step_definition_pattern_type value)
    {
        using map_type = std::unordered_map<step_definition_pattern_type, std::string_view>;

        static const map_type lut = {
            { step_definition_pattern_type::CUCUMBER_EXPRESSION, "CUCUMBER_EXPRESSION" },
            { step_definition_pattern_type::REGULAR_EXPRESSION, "REGULAR_EXPRESSION" },
        };

        return lut.at(value);
    }

    std::ostream& operator<<(std::ostream& stream, step_definition_pattern_type value)
    {
        stream << to_string(value);

        return stream;
    }

    void to_json(nlohmann::json& json, const step_definition_pattern_type& msg)
    {
        json = to_string(msg);
    }

    void from_json(const nlohmann::json& json, step_definition_pattern_type& msg)
    {
        static const std::unordered_map<std::string_view, step_definition_pattern_type> lut = {
            { "CUCUMBER_EXPRESSION", step_definition_pattern_type::CUCUMBER_EXPRESSION },
            { "REGULAR_EXPRESSION", step_definition_pattern_type::REGULAR_EXPRESSION },
        };

        msg = lut.at(json.get<std::string_view>());
    }
}
