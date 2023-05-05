#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/location.hpp>
#include <cucumber/messages/step_keyword_type.hpp>
#include <cucumber/messages/doc_string.hpp>
#include <cucumber/messages/data_table.hpp>

namespace cucumber::messages {

//
// Represents the Step message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A step
//
// Generated code

struct step : cucumber::message
{
    cucumber::messages::location location;
    std::string keyword;
    cucumber::messages::step_keyword_type keyword_type;
    std::string text;
    cucumber::messages::doc_string doc_string;
    cucumber::messages::data_table data_table;
    std::string id;

    std::string to_string() const;
};

}
