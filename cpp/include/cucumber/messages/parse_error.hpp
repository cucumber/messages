#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/source_reference.hpp>

namespace cucumber::messages {

//
// Represents the ParseError message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct parse_error : cucumber::message
{
    cucumber::messages::source_reference source;
    std::string message;

    std::string to_string() const override;
};

}
