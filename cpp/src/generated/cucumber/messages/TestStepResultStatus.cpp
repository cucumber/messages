#include "cucumber/messages/TestStepResultStatus.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <iostream>
#include <string_view>
#include <unordered_map>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    std::string_view to_string(TestStepResultStatus value)
    {
        using map_type = std::unordered_map<TestStepResultStatus, std::string_view>;

        static const map_type lut = {
            { TestStepResultStatus::UNKNOWN, "UNKNOWN" },
            { TestStepResultStatus::PASSED, "PASSED" },
            { TestStepResultStatus::SKIPPED, "SKIPPED" },
            { TestStepResultStatus::PENDING, "PENDING" },
            { TestStepResultStatus::UNDEFINED, "UNDEFINED" },
            { TestStepResultStatus::AMBIGUOUS, "AMBIGUOUS" },
            { TestStepResultStatus::FAILED, "FAILED" },
        };

        return lut.at(value);
    }

    std::ostream& operator<<(std::ostream& stream, TestStepResultStatus value)
    {
        stream << to_string(value);

        return stream;
    }

    void to_json(nlohmann::json& json, const TestStepResultStatus& msg)
    {
        json = to_string(msg);
    }

    void from_json(const nlohmann::json& json, TestStepResultStatus& msg)
    {
        static const std::unordered_map<std::string_view, TestStepResultStatus> lut = {
            { "UNKNOWN", TestStepResultStatus::UNKNOWN },
            { "PASSED", TestStepResultStatus::PASSED },
            { "SKIPPED", TestStepResultStatus::SKIPPED },
            { "PENDING", TestStepResultStatus::PENDING },
            { "UNDEFINED", TestStepResultStatus::UNDEFINED },
            { "AMBIGUOUS", TestStepResultStatus::AMBIGUOUS },
            { "FAILED", TestStepResultStatus::FAILED },
        };

        msg = lut.at(json.get<std::string_view>());
    }
}