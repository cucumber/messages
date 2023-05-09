#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/background.hpp>
#include <cucumber/messages/scenario.hpp>

namespace cucumber::messages {

//
// Represents the RuleChild message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A child node of a `Rule` node
//
// Generated code

struct rule_child
{
    cucumber::messages::background background;
    cucumber::messages::scenario scenario;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const rule_child& msg);

using json = nlohmann::json;

void to_json(json& j, const rule_child& m);

}
