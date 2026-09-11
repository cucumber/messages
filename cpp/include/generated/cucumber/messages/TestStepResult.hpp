#ifndef CUCUMBER_MESSAGES_TEST_STEP_RESULT_HPP
#define CUCUMBER_MESSAGES_TEST_STEP_RESULT_HPP

#include "cucumber/messages/Duration.hpp"
#include "cucumber/messages/Exception.hpp"
#include "cucumber/messages/TestStepResultStatus.hpp"
#include "nlohmann/json_fwd.hpp"
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the TestStepResult message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //

    struct TestStepResult
    {
        Duration duration;
        std::optional<std::string> message;
        TestStepResultStatus status;
        std::optional<Exception> exception;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const TestStepResult& msg);

    void to_json(nlohmann::json& json, const TestStepResult& msg);
    void from_json(const nlohmann::json& json, TestStepResult& msg);
}

#endif
