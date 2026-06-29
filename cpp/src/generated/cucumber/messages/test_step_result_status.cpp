#include "cucumber/messages/test_step_result_status.hpp"
#include "nlohmann/json.hpp"
#include <iostream>
#include <string_view>
#include <unordered_map>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    std::string_view to_string(test_step_result_status value)
    {
        using map_type = std::unordered_map<test_step_result_status, std::string_view>;

        static const map_type lut = {
            { test_step_result_status::UNKNOWN, "UNKNOWN" },
            { test_step_result_status::PASSED, "PASSED" },
            { test_step_result_status::SKIPPED, "SKIPPED" },
            { test_step_result_status::PENDING, "PENDING" },
            { test_step_result_status::UNDEFINED, "UNDEFINED" },
            { test_step_result_status::AMBIGUOUS, "AMBIGUOUS" },
            { test_step_result_status::FAILED, "FAILED" },
        };

        return lut.at(value);
    }

    std::ostream& operator<<(std::ostream& stream, test_step_result_status value)
    {
        stream << to_string(value);

        return stream;
    }

    void to_json(nlohmann::json& json, const test_step_result_status& msg)
    {
        json = to_string(msg);
    }

    void from_json(const nlohmann::json& json, test_step_result_status& msg)
    {
        static const std::unordered_map<std::string_view, test_step_result_status> lut = {
            { "UNKNOWN", test_step_result_status::UNKNOWN },
            { "PASSED", test_step_result_status::PASSED },
            { "SKIPPED", test_step_result_status::SKIPPED },
            { "PENDING", test_step_result_status::PENDING },
            { "UNDEFINED", test_step_result_status::UNDEFINED },
            { "AMBIGUOUS", test_step_result_status::AMBIGUOUS },
            { "FAILED", test_step_result_status::FAILED },
        };

        msg = lut.at(json.get<std::string_view>());
    }
}