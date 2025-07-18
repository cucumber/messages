#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/pickle_step.hpp>
#include <cucumber/messages/pickle_tag.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the Pickle message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A `Pickle` represents a template for a `TestCase`. It is typically derived
// from another format, such as [GherkinDocument](#io.cucumber.messages.GherkinDocument).
// In the future a `Pickle` may be derived from other formats such as Markdown or
// Excel files.
//
// By making `Pickle` the main data structure Cucumber uses for execution, the
// implementation of Cucumber itself becomes simpler, as it doesn't have to deal
// with the complex structure of a [GherkinDocument](#io.cucumber.messages.GherkinDocument).
//
// Each `PickleStep` of a `Pickle` is matched with a `StepDefinition` to create a `TestCase`
//
// Generated code

struct pickle
{
    std::string id;
    std::string uri;
    std::string name;
    std::string language;
    std::vector<cucumber::messages::pickle_step> steps;
    std::vector<cucumber::messages::pickle_tag> tags;
    std::vector<std::string> ast_node_ids;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const pickle& msg);

void to_json(json& j, const pickle& m);

}
