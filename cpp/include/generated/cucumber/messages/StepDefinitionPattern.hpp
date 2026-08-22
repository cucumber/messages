#ifndef CUCUMBER_MESSAGES_STEP_DEFINITION_PATTERN_HPP
#define CUCUMBER_MESSAGES_STEP_DEFINITION_PATTERN_HPP

#include "cucumber/messages/StepDefinitionPatternType.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the StepDefinitionPattern message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //

    struct StepDefinitionPattern
    {
        std::string source;
        StepDefinitionPatternType type;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const StepDefinitionPattern& msg);

    void to_json(nlohmann::json& json, const StepDefinitionPattern& msg);
    void from_json(const nlohmann::json& json, StepDefinitionPattern& msg);
}

#endif
