#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/group.hpp>

namespace cucumber::messages {

//
// Represents the Group message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct group : cucumber::message
{
    std::vector<cucumber::messages::group> children;
    std::size_t start;
    std::string value;

    std::string to_string() const;
};

}
