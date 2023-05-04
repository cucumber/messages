#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/pickle_step.hpp>
#include <cucumber/messages/pickle_tag.hpp>

namespace cucumber::messages {

//
// Represents the Pickle message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// //// Pickles
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

struct pickle : cucumber::message
{
    std::string id;
    std::string uri;
    std::string name;
    std::string language;
    std::vector<cucumber::messages::pickle_step> steps;
    std::vector<cucumber::messages::pickle_tag> tags;
    std::vector<std::string> ast_node_ids;

    std::string to_string() const override;
};

}
