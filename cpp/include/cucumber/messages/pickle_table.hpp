#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/pickle_table_row.hpp>

namespace cucumber::messages {

//
// Represents the PickleTable message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct pickle_table : cucumber::message
{
    std::vector<cucumber::messages::pickle_table_row> rows;

    std::string to_string() const;
};

}
