#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/product.hpp>
#include <cucumber/messages/product.hpp>
#include <cucumber/messages/product.hpp>
#include <cucumber/messages/product.hpp>
#include <cucumber/messages/ci.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the Meta message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// This message contains meta information about the environment. Consumers can use
// this for various purposes.
//
// Generated code

struct meta
{
    std::string protocol_version;
    cucumber::messages::product implementation;
    cucumber::messages::product runtime;
    cucumber::messages::product os;
    cucumber::messages::product cpu;
    std::optional<cucumber::messages::ci> ci;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const meta& msg);

void to_json(json& j, const meta& m);

}
