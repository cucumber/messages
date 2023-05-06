#pragma once

#include <vector>
#include <string>

#include <cucumber/messages/location.hpp>

namespace cucumber::messages {

//
// Represents the DocString message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct doc_string
{
    cucumber::messages::location location;
    std::string media_type;
    std::string content;
    std::string delimiter;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const doc_string& msg);

}
