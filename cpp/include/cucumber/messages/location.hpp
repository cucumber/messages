#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

namespace cucumber::messages {

//
// Represents the Location message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Points to a line and a column in a text file
//
// Generated code

struct location
{
    std::size_t line;
    std::size_t column;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const location& msg);

using json = nlohmann::json;

void to_json(json& j, const location& m);

}
