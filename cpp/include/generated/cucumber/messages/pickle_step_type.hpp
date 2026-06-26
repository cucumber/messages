#ifndef CUCUMBER_MESSAGES_PICKLE_STEP_TYPE_HPP
#define CUCUMBER_MESSAGES_PICKLE_STEP_TYPE_HPP

#include <cstdint>
#include <ostream>
#include <string_view>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    enum class pickle_step_type : std::uint_fast8_t
    {
        UNKNOWN,
        CONTEXT,
        ACTION,
        OUTCOME,
    };

    [[nodiscard]] std::string_view to_string(pickle_step_type value);

    std::ostream& operator<<(std::ostream& stream, pickle_step_type value);
}

#endif
