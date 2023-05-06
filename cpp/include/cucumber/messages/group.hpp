#pragma once

#include <vector>
#include <string>

#include <cucumber/messages/group.hpp>

namespace cucumber::messages {

//
// Represents the Group message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct group
{
    std::vector<cucumber::messages::group> children;
    std::size_t start;
    std::string value;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const group& msg);

}
