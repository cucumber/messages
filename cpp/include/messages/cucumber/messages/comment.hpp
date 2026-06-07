#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/location.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the Comment message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A comment in a Gherkin document
//
// Generated code

struct comment
{
    cucumber::messages::location location;
    std::string text;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const comment& msg);

void to_json(json& j, const comment& m);

}
