#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/step_definition_pattern.hpp>
#include <cucumber/messages/source_reference.hpp>

namespace cucumber::messages {

//
// Represents the StepDefinition message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct step_definition : cucumber::message
{
    std::string id;
    cucumber::messages::step_definition_pattern pattern;
    cucumber::messages::source_reference source_reference;

    std::string to_string() const override;
};

}
