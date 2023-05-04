#pragma once

#include <vector>

#include <cucumber/message.hpp>

namespace cucumber::messages {

//
// Represents the JavaMethod message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct java_method : cucumber::message
{
    std::string class_name;
    std::string method_name;
    std::vector<std::string> method_parameter_types;

    std::string to_string() const override;
};

}
