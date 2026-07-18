#ifndef CUCUMBER_MESSAGES_TEST_STEP_FINISHED_HPP
#define CUCUMBER_MESSAGES_TEST_STEP_FINISHED_HPP

#include "cucumber/messages/TestStepResult.hpp"
#include "cucumber/messages/Timestamp.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the TestStepFinished message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //

    struct TestStepFinished
    {
        std::string testCaseStartedId;
        std::string testStepId;
        std::shared_ptr<TestStepResult> testStepResult;
        std::shared_ptr<Timestamp> timestamp;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const TestStepFinished& msg);

    void to_json(nlohmann::json& json, const TestStepFinished& msg);
    void from_json(const nlohmann::json& json, TestStepFinished& msg);
}

#endif
