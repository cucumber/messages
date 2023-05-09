#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

namespace cucumber::messages {

//
// Represents the UndefinedParameterType message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct undefined_parameter_type
{
    std::string expression;
    std::string name;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const undefined_parameter_type& msg);

using json = nlohmann::json;

void to_json(json& j, const undefined_parameter_type& m);

}
