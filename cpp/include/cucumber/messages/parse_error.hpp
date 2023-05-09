#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/source_reference.hpp>

namespace cucumber::messages {

//
// Represents the ParseError message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct parse_error
{
    cucumber::messages::source_reference source;
    std::string message;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const parse_error& msg);

using json = nlohmann::json;

void to_json(json& j, const parse_error& m);

}
