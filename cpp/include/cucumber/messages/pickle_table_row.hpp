#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/pickle_table_cell.hpp>

namespace cucumber::messages {

//
// Represents the PickleTableRow message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct pickle_table_row : cucumber::message
{
    std::vector<cucumber::messages::pickle_table_cell> cells;

    std::string to_string() const;
};

}
