#pragma once

#include <vector>

#include <cucumber/message.hpp>

namespace cucumber::messages {

//
// Represents the Git message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Information about Git, provided by the Build/CI server as environment
// variables.
//
// Generated code

struct git : cucumber::message
{
    std::string remote;
    std::string revision;
    std::string branch;
    std::string tag;

    std::string to_string() const override;
};

}
