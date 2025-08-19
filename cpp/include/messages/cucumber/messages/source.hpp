#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/source_media_type.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the Source message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A source file, typically a Gherkin document or Java/Ruby/JavaScript source code
//
// Generated code

struct source
{
    std::string uri;
    std::string data;
    cucumber::messages::source_media_type media_type;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const source& msg);

void to_json(json& j, const source& m);

}
