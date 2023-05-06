#pragma once

#include <vector>
#include <string>

#include <cucumber/messages/pickle_doc_string.hpp>
#include <cucumber/messages/pickle_table.hpp>

namespace cucumber::messages {

//
// Represents the PickleStepArgument message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// An optional argument
//
// Generated code

struct pickle_step_argument
{
    cucumber::messages::pickle_doc_string doc_string;
    cucumber::messages::pickle_table data_table;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const pickle_step_argument& msg);

}
