#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/source_reference.hpp>

namespace cucumber::messages {

//
// Represents the ParameterType message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct parameter_type
{
    std::string name;
    std::vector<std::string> regular_expressions;
    bool prefer_for_regular_expression_match;
    bool use_for_snippets;
    std::string id;
    cucumber::messages::source_reference source_reference;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const parameter_type& msg);

using json = nlohmann::json;

void to_json(json& j, const parameter_type& m);

}
