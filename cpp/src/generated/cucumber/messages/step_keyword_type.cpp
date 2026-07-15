#include "cucumber/messages/step_keyword_type.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <iostream>
#include <string_view>
#include <unordered_map>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    std::string_view to_string(step_keyword_type value)
    {
        using map_type = std::unordered_map<step_keyword_type, std::string_view>;

        static const map_type lut = {
            { step_keyword_type::UNKNOWN, "Unknown" },
            { step_keyword_type::CONTEXT, "Context" },
            { step_keyword_type::ACTION, "Action" },
            { step_keyword_type::OUTCOME, "Outcome" },
            { step_keyword_type::CONJUNCTION, "Conjunction" },
        };

        return lut.at(value);
    }

    std::ostream& operator<<(std::ostream& stream, step_keyword_type value)
    {
        stream << to_string(value);

        return stream;
    }

    void to_json(nlohmann::json& json, const step_keyword_type& msg)
    {
        json = to_string(msg);
    }

    void from_json(const nlohmann::json& json, step_keyword_type& msg)
    {
        static const std::unordered_map<std::string_view, step_keyword_type> lut = {
            { "Unknown", step_keyword_type::UNKNOWN },
            { "Context", step_keyword_type::CONTEXT },
            { "Action", step_keyword_type::ACTION },
            { "Outcome", step_keyword_type::OUTCOME },
            { "Conjunction", step_keyword_type::CONJUNCTION },
        };

        msg = lut.at(json.get<std::string_view>());
    }
}
