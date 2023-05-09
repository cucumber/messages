#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/source_media_type.hpp>

namespace cucumber::messages {

//
// Represents the Source message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// //// Source
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
};

std::ostream&
operator<<(std::ostream& os, const source& msg);

using json = nlohmann::json;

void to_json(json& j, const source& m);

}
