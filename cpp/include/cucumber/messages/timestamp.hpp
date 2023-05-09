#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

namespace cucumber::messages {

//
// Represents the Timestamp message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct timestamp
{
    std::size_t seconds;
    std::size_t nanos;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const timestamp& msg);

using json = nlohmann::json;

void to_json(json& j, const timestamp& m);

}
