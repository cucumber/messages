#pragma once

#include <vector>

#include <cucumber/message.hpp>

namespace cucumber::messages {

//
// Represents the Timestamp message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct timestamp : cucumber::message
{
    std::size_t seconds;
    std::size_t nanos;

    std::string to_string() const override;
};

}
