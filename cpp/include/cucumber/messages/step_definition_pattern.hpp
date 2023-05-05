#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/step_definition_pattern_type.hpp>

namespace cucumber::messages {

//
// Represents the StepDefinitionPattern message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct step_definition_pattern : cucumber::message
{
    std::string source;
    cucumber::messages::step_definition_pattern_type type;

    std::string to_string() const;
};

}
