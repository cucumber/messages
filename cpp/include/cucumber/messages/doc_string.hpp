#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/location.hpp>

namespace cucumber::messages {

//
// Represents the DocString message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct doc_string : cucumber::message
{
    cucumber::messages::location location;
    std::string media_type;
    std::string content;
    std::string delimiter;

    std::string to_string() const;
};

}
