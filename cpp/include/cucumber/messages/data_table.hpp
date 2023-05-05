#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/location.hpp>
#include <cucumber/messages/table_row.hpp>

namespace cucumber::messages {

//
// Represents the DataTable message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct data_table : cucumber::message
{
    cucumber::messages::location location;
    std::vector<cucumber::messages::table_row> rows;

    std::string to_string() const;
};

}
