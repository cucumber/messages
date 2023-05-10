#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/location.hpp>
#include <cucumber/messages/tag.hpp>
#include <cucumber/messages/feature_child.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the Feature message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct feature
{
    cucumber::messages::location location;
    std::vector<cucumber::messages::tag> tags;
    std::string language;
    std::string keyword;
    std::string name;
    std::string description;
    std::vector<cucumber::messages::feature_child> children;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const feature& msg);

void to_json(json& j, const feature& m);

}
