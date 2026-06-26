#ifndef CUCUMBER_MESSAGES_TEST_CASE_HPP
#define CUCUMBER_MESSAGES_TEST_CASE_HPP

#include "cucumber/messages/test_step.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

namespace cucumber::messages
{
    //
    // Represents the TestCase message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A `TestCase` contains a sequence of `TestStep`s.
    //
    // Generated code

    struct test_case
    {
        using shared_ptr = test_case;//std::shared_ptr<test_case>;

        std::string id;
        std::string pickle_id;
        std::vector<cucumber::messages::test_step::shared_ptr> test_steps;
        std::optional<std::string> test_run_started_id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const test_case& msg);

    void to_json(nlohmann::json& json, const test_case& msg);
    void from_json(const nlohmann::json& json, test_case& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<test_case>& msg);

}

#endif
