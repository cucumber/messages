#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/step_match_arguments_list.hpp>

namespace cucumber::messages {

//
// Represents the TestStep message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A `TestStep` is derived from either a `PickleStep`
// combined with a `StepDefinition`, or from a `Hook`.
//
// Generated code

struct test_step : cucumber::message
{
    std::string hook_id;
    std::string id;
    std::string pickle_step_id;
    std::vector<std::string> step_definition_ids;
    std::vector<cucumber::messages::step_match_arguments_list> step_match_arguments_lists;

    std::string to_string() const override;
};

}
