#ifndef CUCUMBER_MESSAGES_STEP_DEFINITION_PATTERN_HPP
#define CUCUMBER_MESSAGES_STEP_DEFINITION_PATTERN_HPP

#include "cucumber/messages/step_definition_pattern_type.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the StepDefinitionPattern message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct step_definition_pattern
    {
        using shared_ptr = step_definition_pattern;//std::shared_ptr<step_definition_pattern>;

        std::string source;
        cucumber::messages::step_definition_pattern_type type;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const step_definition_pattern& msg);

    void to_json(nlohmann::json& json, const step_definition_pattern& msg);
    void from_json(const nlohmann::json& json, step_definition_pattern& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<step_definition_pattern>& msg);

}

#endif
