#pragma once

#include <vector>
#include <string>

namespace cucumber::messages {

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
};

std::ostream&
operator<<(std::ostream& os, const java_stack_trace_element& msg);

}
