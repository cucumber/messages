#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/location.hpp>
#include <cucumber/messages/table_cell.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the TableRow message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A row in a table
//
// Generated code

struct table_row
{
    cucumber::messages::location location;
    std::vector<cucumber::messages::table_cell> cells;
    std::string id;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const table_row& msg);

void to_json(json& j, const table_row& m);

}
