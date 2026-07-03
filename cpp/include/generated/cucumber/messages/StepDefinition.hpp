#ifndef CUCUMBER_MESSAGES_STEPDEFINITION_HPP
#define CUCUMBER_MESSAGES_STEPDEFINITION_HPP

#include "cucumber/messages/StepDefinitionPattern.hpp"
#include "cucumber/messages/SourceReference.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the StepDefinition message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct StepDefinition
    {
        std::string id;
        std::shared_ptr<StepDefinitionPattern> pattern;
        std::shared_ptr<SourceReference> sourceReference;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const StepDefinition& msg);

    void to_json(nlohmann::json& json, const StepDefinition& msg);
    void from_json(const nlohmann::json& json, StepDefinition& msg);
}

#endif
