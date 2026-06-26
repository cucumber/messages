#ifndef CUCUMBER_MESSAGES_STEP_KEYWORD_TYPE_HPP
#define CUCUMBER_MESSAGES_STEP_KEYWORD_TYPE_HPP

#include <cstdint>
#include <ostream>
#include <string_view>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    enum class step_keyword_type : std::uint_fast8_t
    {
        UNKNOWN,
        CONTEXT,
        ACTION,
        OUTCOME,
        CONJUNCTION,
    };

    [[nodiscard]] std::string_view to_string(step_keyword_type value);

    std::ostream& operator<<(std::ostream& stream, step_keyword_type value);
}

#endif
