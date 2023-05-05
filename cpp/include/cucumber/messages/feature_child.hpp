#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/rule.hpp>
#include <cucumber/messages/background.hpp>
#include <cucumber/messages/scenario.hpp>

namespace cucumber::messages {

//
// Represents the FeatureChild message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A child node of a `Feature` node
//
// Generated code

struct feature_child : cucumber::message
{
    cucumber::messages::rule rule;
    cucumber::messages::background background;
    cucumber::messages::scenario scenario;

    std::string to_string() const;
};

}
