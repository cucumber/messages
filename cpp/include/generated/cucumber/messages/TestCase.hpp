#ifndef CUCUMBER_MESSAGES_TEST_CASE_HPP
#define CUCUMBER_MESSAGES_TEST_CASE_HPP

#include "cucumber/messages/TestStep.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the TestCase message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A `TestCase` contains a sequence of `TestStep`s.
    //

    struct TestCase
    {
        std::string id;
        std::string pickleId;
        std::vector<std::shared_ptr<TestStep>> testSteps;
        std::optional<std::string> testRunStartedId;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const TestCase& msg);

    void to_json(nlohmann::json& json, const TestCase& msg);
    void from_json(const nlohmann::json& json, TestCase& msg);
}

#endif
