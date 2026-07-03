#ifndef CUCUMBER_MESSAGES_TESTCASEFINISHED_HPP
#define CUCUMBER_MESSAGES_TESTCASEFINISHED_HPP

#include "cucumber/messages/Timestamp.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the TestCaseFinished message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct TestCaseFinished
    {
        std::string testCaseStartedId;
        std::shared_ptr<Timestamp> timestamp;
        bool willBeRetried;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const TestCaseFinished& msg);

    void to_json(nlohmann::json& json, const TestCaseFinished& msg);
    void from_json(const nlohmann::json& json, TestCaseFinished& msg);
}

#endif
