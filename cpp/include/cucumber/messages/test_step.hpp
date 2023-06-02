#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/step_match_arguments_list.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the TestStep message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A `TestStep` is derived from either a `PickleStep`
// combined with a `StepDefinition`, or from a `Hook`.
//
// Generated code

struct test_step
{
    std::optional<std::string> hook_id;
    std::string id;
    std::optional<std::string> pickle_step_id;
    std::optional<std::vector<std::string>> step_definition_ids;
    std::optional<std::vector<cucumber::messages::step_match_arguments_list>> step_match_arguments_lists;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const test_step& msg);

void to_json(json& j, const test_step& m);

}
