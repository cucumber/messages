#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the PickleTag message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A tag
//
// Generated code

struct pickle_tag
{
    std::string name;
    std::string ast_node_id;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const pickle_tag& msg);

void to_json(json& j, const pickle_tag& m);

}
