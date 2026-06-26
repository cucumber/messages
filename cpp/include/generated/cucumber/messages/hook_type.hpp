#ifndef CUCUMBER_MESSAGES_HOOK_TYPE_HPP
#define CUCUMBER_MESSAGES_HOOK_TYPE_HPP

#include "nlohmann/json_fwd.hpp"
#include <cstdint>
#include <ostream>
#include <string_view>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    enum class hook_type : std::uint_fast8_t
    {
        BEFORE_TEST_RUN,
        AFTER_TEST_RUN,
        BEFORE_TEST_CASE,
        AFTER_TEST_CASE,
        BEFORE_TEST_STEP,
        AFTER_TEST_STEP,
    };

    [[nodiscard]] std::string_view to_string(hook_type value);

    std::ostream& operator<<(std::ostream& stream, hook_type value);

    void to_json(nlohmann::json& json, const hook_type& msg);
}

#endif
