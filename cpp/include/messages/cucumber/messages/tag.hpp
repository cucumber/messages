#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/location.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the Tag message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A tag
//
// Generated code

struct tag
{
    cucumber::messages::location location;
    std::string name;
    std::string id;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const tag& msg);

void to_json(json& j, const tag& m);

}
