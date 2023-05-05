#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/location.hpp>
#include <cucumber/messages/table_cell.hpp>

namespace cucumber::messages {

//
// Represents the TableRow message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A row in a table
//
// Generated code

struct table_row : cucumber::message
{
    cucumber::messages::location location;
    std::vector<cucumber::messages::table_cell> cells;
    std::string id;

    std::string to_string() const;
};

}
