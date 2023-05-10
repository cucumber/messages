#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/step_match_argument.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the StepMatchArgumentsList message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct step_match_arguments_list
{
    std::vector<cucumber::messages::step_match_argument> step_match_arguments;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const step_match_arguments_list& msg);

void to_json(json& j, const step_match_arguments_list& m);

}
