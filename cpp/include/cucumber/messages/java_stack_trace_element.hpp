#pragma once

#include <vector>

#include <cucumber/message.hpp>

namespace cucumber::messages {

//
// Represents the JavaStackTraceElement message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct java_stack_trace_element : cucumber::message
{
    std::string class_name;
    std::string file_name;
    std::string method_name;

    std::string to_string() const override;
};

}
