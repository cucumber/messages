#ifndef CUCUMBER_MESSAGES_TESTSTEP_HPP
#define CUCUMBER_MESSAGES_TESTSTEP_HPP

#include "cucumber/messages/StepMatchArgumentsList.hpp"
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

    struct TestStep
    {
        std::optional<std::string> hookId;
        std::string id;
        std::optional<std::string> pickleStepId;
        std::optional<std::vector<std::string>> stepDefinitionIds;
        std::optional<std::vector<std::shared_ptr<StepMatchArgumentsList>>> stepMatchArgumentsLists;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const TestStep& msg);

    void to_json(nlohmann::json& json, const TestStep& msg);
    void from_json(const nlohmann::json& json, TestStep& msg);
}

#endif
