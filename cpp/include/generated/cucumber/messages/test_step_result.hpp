#ifndef CUCUMBER_MESSAGES_TEST_STEP_RESULT_HPP
#define CUCUMBER_MESSAGES_TEST_STEP_RESULT_HPP

#include "cucumber/messages/duration.hpp"
#include "cucumber/messages/exception.hpp"
#include "cucumber/messages/test_step_result_status.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the TestStepResult message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct test_step_result
    {
        using shared_ptr = test_step_result;//std::shared_ptr<test_step_result>;

        cucumber::messages::duration::shared_ptr duration;
        std::optional<std::string> message;
        cucumber::messages::test_step_result_status status;
        std::optional<cucumber::messages::exception::shared_ptr> exception;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const test_step_result& msg);

    void to_json(nlohmann::json& json, const test_step_result& msg);
    void from_json(const nlohmann::json& json, test_step_result& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<test_step_result>& msg);

}

#endif
