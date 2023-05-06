#pragma once

#include <vector>
#include <string>

#include <cucumber/messages/pickle_table_row.hpp>

namespace cucumber::messages {

//
// Represents the PickleTable message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct pickle_table
{
    std::vector<cucumber::messages::pickle_table_row> rows;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const pickle_table& msg);

}
