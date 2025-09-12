#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/snippet.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the Suggestion message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A suggested fragment of code to implement an undefined step
//
// Generated code

struct suggestion
{
    std::string id;
    std::string pickle_step_id;
    std::vector<cucumber::messages::snippet> snippets;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const suggestion& msg);

void to_json(json& j, const suggestion& m);

}
