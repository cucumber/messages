#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the Duration message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// The structure is pretty close of the Timestamp one. For clarity, a second type
// of message is used.
//
// Generated code

struct duration
{
    std::size_t seconds;
    std::size_t nanos;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const duration& msg);

void to_json(json& j, const duration& m);

}
