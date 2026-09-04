#ifndef CUCUMBER_MESSAGES_STEP_DEFINITION_PATTERN_TYPE_HPP
#define CUCUMBER_MESSAGES_STEP_DEFINITION_PATTERN_TYPE_HPP

#include "nlohmann/json_fwd.hpp"
#include <cstdint>
#include <ostream>
#include <string_view>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    enum class StepDefinitionPatternType : std::uint_fast8_t
    {
        CUCUMBER_EXPRESSION,
        REGULAR_EXPRESSION,
    };

    [[nodiscard]] std::string_view to_string(StepDefinitionPatternType value);

    std::ostream& operator<<(std::ostream& stream, StepDefinitionPatternType value);

    void to_json(nlohmann::json& json, const StepDefinitionPatternType& msg);
    void from_json(const nlohmann::json& json, StepDefinitionPatternType& msg);
}

#endif
