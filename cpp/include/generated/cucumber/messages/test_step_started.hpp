#ifndef CUCUMBER_MESSAGES_TEST_STEP_STARTED_HPP
#define CUCUMBER_MESSAGES_TEST_STEP_STARTED_HPP

#include "cucumber/messages/timestamp.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the TestStepStarted message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct test_step_started
    {
        std::string test_case_started_id;
        std::string test_step_id;
        cucumber::messages::timestamp timestamp;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const test_step_started& msg);

    void to_json(nlohmann::json& json, const test_step_started& msg);
    void from_json(const nlohmann::json& json, test_step_started& msg);
}

#endif
