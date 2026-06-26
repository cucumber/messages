#include "cucumber/messages/step_keyword_type.hpp"
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
}
