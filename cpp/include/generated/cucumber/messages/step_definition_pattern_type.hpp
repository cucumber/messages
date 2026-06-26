#ifndef CUCUMBER_MESSAGES_STEP_DEFINITION_PATTERN_TYPE_HPP
#define CUCUMBER_MESSAGES_STEP_DEFINITION_PATTERN_TYPE_HPP

#include <cstdint>
#include <ostream>
#include <string_view>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    enum class step_definition_pattern_type : std::uint_fast8_t
    {
        CUCUMBER_EXPRESSION,
        REGULAR_EXPRESSION,
    };

    [[nodiscard]] std::string_view to_string(step_definition_pattern_type value);

    std::ostream& operator<<(std::ostream& stream, step_definition_pattern_type value);
}

#endif
