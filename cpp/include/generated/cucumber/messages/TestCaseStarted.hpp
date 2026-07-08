#ifndef CUCUMBER_MESSAGES_TEST_CASE_STARTED_HPP
#define CUCUMBER_MESSAGES_TEST_CASE_STARTED_HPP

#include "cucumber/messages/Timestamp.hpp"
#include "nlohmann/json_fwd.hpp"
#include <cstddef>
#include <memory>
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the TestCaseStarted message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct TestCaseStarted
    {
        std::size_t attempt;
        std::string id;
        std::string testCaseId;
        std::optional<std::string> workerId;
        std::shared_ptr<Timestamp> timestamp;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const TestCaseStarted& msg);

    void to_json(nlohmann::json& json, const TestCaseStarted& msg);
    void from_json(const nlohmann::json& json, TestCaseStarted& msg);
}

#endif
