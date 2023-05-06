#pragma once

#include <vector>
#include <string>

namespace cucumber::messages {

//
// Represents the Duration message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// The structure is pretty close of the Timestamp one. For clarity, a second type
// of message is used.
//
// Generated code

struct duration
{
    std::size_t seconds;
    std::size_t nanos;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const duration& msg);

}
