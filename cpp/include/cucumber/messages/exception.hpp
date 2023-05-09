#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

namespace cucumber::messages {

//
// Represents the Exception message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A simplified representation of an exception
//
// Generated code

struct exception
{
    std::string type;
    std::string message;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const exception& msg);

using json = nlohmann::json;

void to_json(json& j, const exception& m);

}
