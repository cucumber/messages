#ifndef CUCUMBER_MESSAGES_STEP_MATCH_ARGUMENT_HPP
#define CUCUMBER_MESSAGES_STEP_MATCH_ARGUMENT_HPP

#include "cucumber/messages/Group.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the StepMatchArgument message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Represents a single argument extracted from a step match and passed to a step definition.
    // This is used for the following purposes:
    // - Construct an argument to pass to a step definition (possibly through a parameter type transform)
    // - Highlight the matched parameter in rich formatters such as the HTML formatter
    //
    // This message closely matches the `Argument` class in the `cucumber-expressions` library.
    //

    struct StepMatchArgument
    {
        std::shared_ptr<Group> group;
        std::optional<std::string> parameterTypeName;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const StepMatchArgument& msg);

    void to_json(nlohmann::json& json, const StepMatchArgument& msg);
    void from_json(const nlohmann::json& json, StepMatchArgument& msg);
}

#endif
