#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/feature.hpp>
#include <cucumber/messages/comment.hpp>

namespace cucumber::messages {

//
// Represents the GherkinDocument message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// The [AST](https://en.wikipedia.org/wiki/Abstract_syntax_tree) of a Gherkin document.
// Cucumber implementations should *not* depend on `GherkinDocument` or any of its
// children for execution - use [Pickle](#io.cucumber.messages.Pickle) instead.
//
// The only consumers of `GherkinDocument` should only be formatters that produce
// "rich" output, resembling the original Gherkin document.
//
// Generated code

struct gherkin_document
{
    std::string uri;
    cucumber::messages::feature feature;
    std::vector<cucumber::messages::comment> comments;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const gherkin_document& msg);

using json = nlohmann::json;

void to_json(json& j, const gherkin_document& m);

}
