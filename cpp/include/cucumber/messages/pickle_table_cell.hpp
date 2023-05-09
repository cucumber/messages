#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

namespace cucumber::messages {

//
// Represents the PickleTableCell message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct pickle_table_cell
{
    std::string value;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const pickle_table_cell& msg);

using json = nlohmann::json;

void to_json(json& j, const pickle_table_cell& m);

}
