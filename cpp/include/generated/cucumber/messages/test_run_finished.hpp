#ifndef CUCUMBER_MESSAGES_TEST_RUN_FINISHED_HPP
#define CUCUMBER_MESSAGES_TEST_RUN_FINISHED_HPP

#include "cucumber/messages/exception.hpp"
#include "cucumber/messages/timestamp.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the TestRunFinished message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct test_run_finished
    {
        using shared_ptr = test_run_finished;//std::shared_ptr<test_run_finished>;

        std::optional<std::string> message;
        bool success;
        cucumber::messages::timestamp::shared_ptr timestamp;
        std::optional<cucumber::messages::exception::shared_ptr> exception;
        std::optional<std::string> test_run_started_id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const test_run_finished& msg);

    void to_json(nlohmann::json& json, const test_run_finished& msg);
    void from_json(const nlohmann::json& json, test_run_finished& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<test_run_finished>& msg);

}

#endif
