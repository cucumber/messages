#ifndef CUCUMBER_MESSAGES_TEST_STEP_RESULT_STATUS_HPP
#define CUCUMBER_MESSAGES_TEST_STEP_RESULT_STATUS_HPP

#include "nlohmann/json_fwd.hpp"
#include <cstdint>
#include <ostream>
#include <string_view>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    enum class test_step_result_status : std::uint_fast8_t
    {
        UNKNOWN,
        PASSED,
        SKIPPED,
        PENDING,
        UNDEFINED,
        AMBIGUOUS,
        FAILED,
    };

    [[nodiscard]] std::string_view to_string(test_step_result_status value);

    std::ostream& operator<<(std::ostream& stream, test_step_result_status value);

    void to_json(nlohmann::json& json, const test_step_result_status& msg);
    void from_json(const nlohmann::json& json, test_step_result_status& msg);
}

#endif
