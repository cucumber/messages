#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/location.hpp>
#include <cucumber/messages/step.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the Background message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct background
{
    cucumber::messages::location location;
    std::string keyword;
    std::string name;
    std::string description;
    std::vector<cucumber::messages::step> steps;
    std::string id;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const background& msg);

void to_json(json& j, const background& m);

}
