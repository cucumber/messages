#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/java_method.hpp>
#include <cucumber/messages/java_stack_trace_element.hpp>
#include <cucumber/messages/location.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

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
    std::optional<std::string> uri;
    std::optional<cucumber::messages::java_method> java_method;
    std::optional<cucumber::messages::java_stack_trace_element> java_stack_trace_element;
    std::optional<cucumber::messages::location> location;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const source_reference& msg);

void to_json(json& j, const source_reference& m);

}
