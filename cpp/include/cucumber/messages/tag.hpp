#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/location.hpp>

namespace cucumber::messages {

//
// Represents the Tag message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A tag
//
// Generated code

struct tag : cucumber::message
{
    cucumber::messages::location location;
    std::string name;
    std::string id;

    std::string to_string() const;
};

}
