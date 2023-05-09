#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/step_definition_pattern_type.hpp>

namespace cucumber::messages {

//
// Represents the StepDefinitionPattern message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct step_definition_pattern
{
    std::string source;
    cucumber::messages::step_definition_pattern_type type;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const step_definition_pattern& msg);

using json = nlohmann::json;

void to_json(json& j, const step_definition_pattern& m);

}
