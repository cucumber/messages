#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/location.hpp>
#include <cucumber/messages/step_keyword_type.hpp>
#include <cucumber/messages/doc_string.hpp>
#include <cucumber/messages/data_table.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the Step message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// A step
//
// Generated code

struct step
{
    cucumber::messages::location location;
    std::string keyword;
    std::optional<cucumber::messages::step_keyword_type> keyword_type;
    std::string text;
    std::optional<cucumber::messages::doc_string> doc_string;
    std::optional<cucumber::messages::data_table> data_table;
    std::string id;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const step& msg);

void to_json(json& j, const step& m);

}
