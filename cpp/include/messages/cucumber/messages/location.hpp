#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

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
    std::optional<std::size_t> column;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const location& msg);

void to_json(json& j, const location& m);

}
