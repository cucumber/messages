#ifndef CUCUMBER_MESSAGES_STEP_DEFINITION_HPP
#define CUCUMBER_MESSAGES_STEP_DEFINITION_HPP

#include "cucumber/messages/step_definition_pattern.hpp"
#include "cucumber/messages/source_reference.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the StepDefinition message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct step_definition
    {
        std::string id;
        cucumber::messages::step_definition_pattern pattern;
        cucumber::messages::source_reference source_reference;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const step_definition& msg);

    void to_json(nlohmann::json& json, const step_definition& msg);
    void from_json(const nlohmann::json& json, step_definition& msg);
}

#endif
