#pragma once

#include <vector>
#include <string>

#include <cucumber/messages/source_reference.hpp>

namespace cucumber::messages {

//
// Represents the Hook message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct hook
{
    std::string id;
    std::string name;
    cucumber::messages::source_reference source_reference;
    std::string tag_expression;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const hook& msg);

}
