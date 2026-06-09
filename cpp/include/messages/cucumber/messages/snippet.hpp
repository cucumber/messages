#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the Snippet message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct snippet
{
    std::string language;
    std::string code;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const snippet& msg);

void to_json(json& j, const snippet& m);

}
