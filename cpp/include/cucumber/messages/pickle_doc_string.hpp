#pragma once

#include <vector>
#include <string>

namespace cucumber::messages {

//
// Represents the PickleDocString message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct pickle_doc_string
{
    std::string media_type;
    std::string content;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const pickle_doc_string& msg);

}
