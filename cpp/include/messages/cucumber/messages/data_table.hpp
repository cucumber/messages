#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/location.hpp>
#include <cucumber/messages/table_row.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the DataTable message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct data_table
{
    cucumber::messages::location location;
    std::vector<cucumber::messages::table_row> rows;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const data_table& msg);

void to_json(json& j, const data_table& m);

}
