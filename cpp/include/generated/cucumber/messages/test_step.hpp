#ifndef CUCUMBER_MESSAGES_TEST_STEP_HPP
#define CUCUMBER_MESSAGES_TEST_STEP_HPP

#include "cucumber/messages/step_match_arguments_list.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

namespace cucumber::messages
{
    //
    // Represents the TestStep message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A `TestStep` is derived from either a `PickleStep` combined with a `StepDefinition`, or from a `Hook`.
    //
    // When derived from a PickleStep:
    // * For `UNDEFINED` steps `stepDefinitionIds` and `stepMatchArgumentsLists` will be empty.
    // * For `AMBIGUOUS` steps, there will be multiple entries in `stepDefinitionIds` and `stepMatchArgumentsLists`. The first entry in the stepMatchArgumentsLists holds the list of arguments for the first matching step definition, the second entry for the second, etc
    //
    // Generated code

    struct test_step
    {
        std::optional<std::string> hook_id;
        std::string id;
        std::optional<std::string> pickle_step_id;
        std::optional<std::vector<std::string>> step_definition_ids;
        std::optional<std::vector<cucumber::messages::step_match_arguments_list>> step_match_arguments_lists;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const test_step& msg);

    void to_json(nlohmann::json& json, const test_step& msg);
    void from_json(const nlohmann::json& json, test_step& msg);
}

#endif
