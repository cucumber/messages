#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the Git message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Information about Git, provided by the Build/CI server as environment
// variables.
//
// Generated code

struct git
{
    std::string remote;
    std::string revision;
    std::string branch;
    std::string tag;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const git& msg);

void to_json(json& j, const git& m);

}
