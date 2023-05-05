#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/git.hpp>

namespace cucumber::messages {

//
// Represents the Ci message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// CI environment
//
// Generated code

struct ci : cucumber::message
{
    std::string name;
    std::string url;
    std::string build_number;
    cucumber::messages::git git;

    std::string to_string() const;
};

}
