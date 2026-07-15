#ifndef CUCUMBER_MESSAGES_STEP_MATCH_ARGUMENT_HPP
#define CUCUMBER_MESSAGES_STEP_MATCH_ARGUMENT_HPP

#include "cucumber/messages/group.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

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
    // Generated code

    struct step_match_argument
    {
        cucumber::messages::group group;
        std::optional<std::string> parameter_type_name;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const step_match_argument& msg);

    void to_json(nlohmann::json& json, const step_match_argument& msg);
    void from_json(const nlohmann::json& json, step_match_argument& msg);
}

#endif
