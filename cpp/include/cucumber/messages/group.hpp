#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/group.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the Group message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct group
{
    std::vector<cucumber::messages::group> children;
    std::optional<std::size_t> start;
    std::optional<std::string> value;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const group& msg);

void to_json(json& j, const group& m);

}
