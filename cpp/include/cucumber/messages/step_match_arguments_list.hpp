#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/step_match_argument.hpp>

namespace cucumber::messages {

//
// Represents the StepMatchArgumentsList message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct step_match_arguments_list : cucumber::message
{
    std::vector<cucumber::messages::step_match_argument> step_match_arguments;

    std::string to_string() const;
};

}
