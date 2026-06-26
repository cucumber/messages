#include "cucumber/messages/pickle_step_type.hpp"
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
}
