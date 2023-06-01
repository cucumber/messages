#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/rule.hpp>
#include <cucumber/messages/background.hpp>
#include <cucumber/messages/scenario.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the FeatureChild message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A child node of a `Feature` node
//
// Generated code

struct feature_child
{
    std::optional<cucumber::messages::rule> rule;
    std::optional<cucumber::messages::background> background;
    std::optional<cucumber::messages::scenario> scenario;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const feature_child& msg);

void to_json(json& j, const feature_child& m);

}
