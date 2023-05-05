#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/pickle_step_argument.hpp>
#include <cucumber/messages/pickle_step_type.hpp>

namespace cucumber::messages {

//
// Represents the PickleStep message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// An executable step
//
// Generated code

struct pickle_step : cucumber::message
{
    cucumber::messages::pickle_step_argument argument;
    std::vector<std::string> ast_node_ids;
    std::string id;
    cucumber::messages::pickle_step_type type;
    std::string text;

    std::string to_string() const;
};

}
