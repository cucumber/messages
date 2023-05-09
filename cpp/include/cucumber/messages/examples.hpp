#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/location.hpp>
#include <cucumber/messages/tag.hpp>
#include <cucumber/messages/table_row.hpp>
#include <cucumber/messages/table_row.hpp>

namespace cucumber::messages {

//
// Represents the Examples message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct examples
{
    cucumber::messages::location location;
    std::vector<cucumber::messages::tag> tags;
    std::string keyword;
    std::string name;
    std::string description;
    cucumber::messages::table_row table_header;
    std::vector<cucumber::messages::table_row> table_body;
    std::string id;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const examples& msg);

using json = nlohmann::json;

void to_json(json& j, const examples& m);

}
