#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/pickle_doc_string.hpp>
#include <cucumber/messages/pickle_table.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the PickleStepArgument message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// An optional argument
//
// Generated code

struct pickle_step_argument
{
    std::optional<cucumber::messages::pickle_doc_string> doc_string;
    std::optional<cucumber::messages::pickle_table> data_table;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const pickle_step_argument& msg);

void to_json(json& j, const pickle_step_argument& m);

}
