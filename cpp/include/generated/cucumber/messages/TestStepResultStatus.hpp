#ifndef CUCUMBER_MESSAGES_TEST_STEP_RESULT_STATUS_HPP
#define CUCUMBER_MESSAGES_TEST_STEP_RESULT_STATUS_HPP

#include "nlohmann/json_fwd.hpp"
#include <cstdint>
#include <ostream>
#include <string_view>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    enum class TestStepResultStatus : std::uint_fast8_t
    {
        UNKNOWN,
        PASSED,
        SKIPPED,
        PENDING,
        UNDEFINED,
        AMBIGUOUS,
        FAILED,
    };

    [[nodiscard]] std::string_view to_string(TestStepResultStatus value);

    std::ostream& operator<<(std::ostream& stream, TestStepResultStatus value);

    void to_json(nlohmann::json& json, const TestStepResultStatus& msg);
    void from_json(const nlohmann::json& json, TestStepResultStatus& msg);
}

#endif
