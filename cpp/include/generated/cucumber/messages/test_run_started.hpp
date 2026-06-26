#ifndef CUCUMBER_MESSAGES_TEST_RUN_STARTED_HPP
#define CUCUMBER_MESSAGES_TEST_RUN_STARTED_HPP

#include "cucumber/messages/timestamp.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the TestRunStarted message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct test_run_started
    {
        using shared_ptr = test_run_started;//std::shared_ptr<test_run_started>;

        cucumber::messages::timestamp::shared_ptr timestamp;
        std::optional<std::string> id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const test_run_started& msg);

    void to_json(nlohmann::json& json, const test_run_started& msg);
    void from_json(const nlohmann::json& json, test_run_started& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<test_run_started>& msg);

}

#endif
