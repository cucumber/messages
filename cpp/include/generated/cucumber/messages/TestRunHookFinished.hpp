#ifndef CUCUMBER_MESSAGES_TEST_RUN_HOOK_FINISHED_HPP
#define CUCUMBER_MESSAGES_TEST_RUN_HOOK_FINISHED_HPP

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
    // Represents the TestRunHookFinished message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct TestRunHookFinished
    {
        std::string testRunHookStartedId;
        std::shared_ptr<TestStepResult> result;
        std::shared_ptr<Timestamp> timestamp;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const TestRunHookFinished& msg);

    void to_json(nlohmann::json& json, const TestRunHookFinished& msg);
    void from_json(const nlohmann::json& json, TestRunHookFinished& msg);
}

#endif
