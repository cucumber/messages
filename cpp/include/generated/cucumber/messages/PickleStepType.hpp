#ifndef CUCUMBER_MESSAGES_PICKLE_STEP_TYPE_HPP
#define CUCUMBER_MESSAGES_PICKLE_STEP_TYPE_HPP

#include "nlohmann/json_fwd.hpp"
#include <cstdint>
#include <ostream>
#include <string_view>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    enum class PickleStepType : std::uint_fast8_t
    {
        UNKNOWN,
        CONTEXT,
        ACTION,
        OUTCOME,
    };

    [[nodiscard]] std::string_view to_string(PickleStepType value);

    std::ostream& operator<<(std::ostream& stream, PickleStepType value);

    void to_json(nlohmann::json& json, const PickleStepType& msg);
    void from_json(const nlohmann::json& json, PickleStepType& msg);
}

#endif
