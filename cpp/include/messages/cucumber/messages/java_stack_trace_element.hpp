#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the JavaStackTraceElement message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct java_stack_trace_element
{
    std::string class_name;
    std::string file_name;
    std::string method_name;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const java_stack_trace_element& msg);

void to_json(json& j, const java_stack_trace_element& m);

}
