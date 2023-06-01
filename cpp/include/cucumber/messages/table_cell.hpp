#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/location.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the TableCell message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A cell in a `TableRow`
//
// Generated code

struct table_cell
{
    cucumber::messages::location location;
    std::string value;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const table_cell& msg);

void to_json(json& j, const table_cell& m);

}
