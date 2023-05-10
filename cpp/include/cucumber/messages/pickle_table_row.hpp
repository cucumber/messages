#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/pickle_table_cell.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the PickleTableRow message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct pickle_table_row
{
    std::vector<cucumber::messages::pickle_table_cell> cells;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const pickle_table_row& msg);

void to_json(json& j, const pickle_table_row& m);

}
