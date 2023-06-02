#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/source_reference.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the Hook message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct hook
{
    std::string id;
    std::optional<std::string> name;
    cucumber::messages::source_reference source_reference;
    std::optional<std::string> tag_expression;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const hook& msg);

void to_json(json& j, const hook& m);

}
