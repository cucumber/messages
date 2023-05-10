#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/step_definition_pattern.hpp>
#include <cucumber/messages/source_reference.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

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

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const step_definition& msg);

void to_json(json& j, const step_definition& m);

}
