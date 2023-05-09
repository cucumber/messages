#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/java_method.hpp>
#include <cucumber/messages/java_stack_trace_element.hpp>
#include <cucumber/messages/location.hpp>

namespace cucumber::messages {

//
// Represents the SourceReference message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Points to a [Source](#io.cucumber.messages.Source) identified by `uri` and a
// [Location](#io.cucumber.messages.Location) within that file.
//
// Generated code

struct source_reference
{
    std::string uri;
    cucumber::messages::java_method java_method;
    cucumber::messages::java_stack_trace_element java_stack_trace_element;
    cucumber::messages::location location;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const source_reference& msg);

using json = nlohmann::json;

void to_json(json& j, const source_reference& m);

}
