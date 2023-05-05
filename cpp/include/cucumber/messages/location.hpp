#pragma once

#include <vector>

#include <cucumber/message.hpp>

namespace cucumber::messages {

//
// Represents the Location message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Points to a line and a column in a text file
//
// Generated code

struct location : cucumber::message
{
    std::size_t line;
    std::size_t column;

    std::string to_string() const;
};

}
