#pragma once

#include <vector>

#include <cucumber/message.hpp>

namespace cucumber::messages {

//
// Represents the Exception message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A simplified representation of an exception
//
// Generated code

struct exception : cucumber::message
{
    std::string type;
    std::string message;

    std::string to_string() const;
};

}
