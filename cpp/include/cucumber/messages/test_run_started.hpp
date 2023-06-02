#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/timestamp.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the TestRunStarted message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct test_run_started
{
    cucumber::messages::timestamp timestamp;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const test_run_started& msg);

void to_json(json& j, const test_run_started& m);

}
