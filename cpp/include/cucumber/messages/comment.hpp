#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/location.hpp>

namespace cucumber::messages {

//
// Represents the Comment message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A comment in a Gherkin document
//
// Generated code

struct comment : cucumber::message
{
    cucumber::messages::location location;
    std::string text;

    std::string to_string() const;
};

}
