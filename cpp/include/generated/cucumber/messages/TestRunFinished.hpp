#ifndef CUCUMBER_MESSAGES_TEST_RUN_FINISHED_HPP
#define CUCUMBER_MESSAGES_TEST_RUN_FINISHED_HPP

#include "cucumber/messages/Exception.hpp"
#include "cucumber/messages/Timestamp.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the TestRunFinished message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct TestRunFinished
    {
        std::optional<std::string> message;
        bool success;
        std::shared_ptr<Timestamp> timestamp;
        std::optional<std::shared_ptr<Exception>> exception;
        std::optional<std::string> testRunStartedId;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const TestRunFinished& msg);

    void to_json(nlohmann::json& json, const TestRunFinished& msg);
    void from_json(const nlohmann::json& json, TestRunFinished& msg);
}

#endif
