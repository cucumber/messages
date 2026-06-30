#ifndef CUCUMBER_MESSAGES_TEST_RUN_HOOK_FINISHED_HPP
#define CUCUMBER_MESSAGES_TEST_RUN_HOOK_FINISHED_HPP

#include "cucumber/messages/test_step_result.hpp"
#include "cucumber/messages/timestamp.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the TestRunHookFinished message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct test_run_hook_finished
    {
        std::string test_run_hook_started_id;
        cucumber::messages::test_step_result result;
        cucumber::messages::timestamp timestamp;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const test_run_hook_finished& msg);

    void to_json(nlohmann::json& json, const test_run_hook_finished& msg);
    void from_json(const nlohmann::json& json, test_run_hook_finished& msg);
}

#endif
