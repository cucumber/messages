#include "cucumber/messages/step_definition_pattern_type.hpp"
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
}
