#pragma once

#include <vector>

#include <cucumber/message.hpp>

namespace cucumber::messages {

//
// Represents the UndefinedParameterType message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct undefined_parameter_type : cucumber::message
{
    std::string expression;
    std::string name;

    std::string to_string() const;
};

}
