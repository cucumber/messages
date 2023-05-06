#pragma once

#include <vector>
#include <string>

namespace cucumber::messages {

//
// Represents the Product message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Used to describe various properties of Meta
//
// Generated code

struct product
{
    std::string name;
    std::string version;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const product& msg);

}
