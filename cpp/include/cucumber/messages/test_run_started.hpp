#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/timestamp.hpp>

namespace cucumber::messages {

//
// Represents the TestRunStarted message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct test_run_started
{
    cucumber::messages::timestamp timestamp;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const test_run_started& msg);

using json = nlohmann::json;

void to_json(json& j, const test_run_started& m);

}
