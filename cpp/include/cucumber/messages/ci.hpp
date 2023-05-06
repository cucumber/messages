#pragma once

#include <vector>
#include <string>

#include <cucumber/messages/git.hpp>

namespace cucumber::messages {

//
// Represents the Ci message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// CI environment
//
// Generated code

struct ci
{
    std::string name;
    std::string url;
    std::string build_number;
    cucumber::messages::git git;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const ci& msg);

}
