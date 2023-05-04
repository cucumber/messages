#pragma once

#include <vector>

#include <cucumber/message.hpp>

namespace cucumber::messages {

//
// Represents the PickleTag message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A tag
//
// Generated code

struct pickle_tag : cucumber::message
{
    std::string name;
    std::string ast_node_id;

    std::string to_string() const override;
};

}
