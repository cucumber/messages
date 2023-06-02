#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the Product message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Used to describe various properties of Meta
//
// Generated code

struct product
{
    std::string name;
    std::optional<std::string> version;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const product& msg);

void to_json(json& j, const product& m);

}
