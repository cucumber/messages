#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/location.hpp>

namespace cucumber::messages {

//
// Represents the TableCell message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A cell in a `TableRow`
//
// Generated code

struct table_cell : cucumber::message
{
    cucumber::messages::location location;
    std::string value;

    std::string to_string() const override;
};

}
