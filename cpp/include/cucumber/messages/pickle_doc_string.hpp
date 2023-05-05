#pragma once

#include <vector>

#include <cucumber/message.hpp>

namespace cucumber::messages {

//
// Represents the PickleDocString message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct pickle_doc_string : cucumber::message
{
    std::string media_type;
    std::string content;

    std::string to_string() const;
};

}
