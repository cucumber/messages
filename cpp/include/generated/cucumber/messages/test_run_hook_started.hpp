#ifndef CUCUMBER_MESSAGES_TEST_RUN_HOOK_STARTED_HPP
#define CUCUMBER_MESSAGES_TEST_RUN_HOOK_STARTED_HPP

#include "cucumber/messages/timestamp.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the TestRunHookStarted message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct test_run_hook_started
    {
        using shared_ptr = test_run_hook_started;//std::shared_ptr<test_run_hook_started>;

        std::string id;
        std::string test_run_started_id;
        std::string hook_id;
        std::optional<std::string> worker_id;
        cucumber::messages::timestamp::shared_ptr timestamp;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const test_run_hook_started& msg);

    void to_json(nlohmann::json& json, const test_run_hook_started& msg);
    void from_json(const nlohmann::json& json, test_run_hook_started& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<test_run_hook_started>& msg);

}

#endif
