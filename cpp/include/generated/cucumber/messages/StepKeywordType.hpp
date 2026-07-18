#ifndef CUCUMBER_MESSAGES_STEP_KEYWORD_TYPE_HPP
#define CUCUMBER_MESSAGES_STEP_KEYWORD_TYPE_HPP

#include "nlohmann/json_fwd.hpp"
#include <cstdint>
#include <ostream>
#include <string_view>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    enum class StepKeywordType : std::uint_fast8_t
    {
        UNKNOWN,
        CONTEXT,
        ACTION,
        OUTCOME,
        CONJUNCTION,
    };

    [[nodiscard]] std::string_view to_string(StepKeywordType value);

    std::ostream& operator<<(std::ostream& stream, StepKeywordType value);

    void to_json(nlohmann::json& json, const StepKeywordType& msg);
    void from_json(const nlohmann::json& json, StepKeywordType& msg);
}

#endif
