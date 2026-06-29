#include "cucumber/messages/pickle_step_type.hpp"
#include "nlohmann/json.hpp"
#include <iostream>
#include <string_view>
#include <unordered_map>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    std::string_view to_string(pickle_step_type value)
    {
        using map_type = std::unordered_map<pickle_step_type, std::string_view>;

        static const map_type lut = {
            { pickle_step_type::UNKNOWN, "Unknown" },
            { pickle_step_type::CONTEXT, "Context" },
            { pickle_step_type::ACTION, "Action" },
            { pickle_step_type::OUTCOME, "Outcome" },
        };

        return lut.at(value);
    }

    std::ostream& operator<<(std::ostream& stream, pickle_step_type value)
    {
        stream << to_string(value);

        return stream;
    }

    void to_json(nlohmann::json& json, const pickle_step_type& msg)
    {
        json = to_string(msg);
    }

    void from_json(const nlohmann::json& json, pickle_step_type& msg)
    {
        static const std::unordered_map<std::string_view, pickle_step_type> lut = {
            { "Unknown", pickle_step_type::UNKNOWN },
            { "Context", pickle_step_type::CONTEXT },
            { "Action", pickle_step_type::ACTION },
            { "Outcome", pickle_step_type::OUTCOME },
        };

        msg = lut.at(json.get<std::string_view>());
    }
}
