#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/timestamp.hpp>

namespace cucumber::messages {

//
// Represents the TestCaseFinished message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct test_case_finished
{
    std::string test_case_started_id;
    cucumber::messages::timestamp timestamp;
    bool will_be_retried;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const test_case_finished& msg);

using json = nlohmann::json;

void to_json(json& j, const test_case_finished& m);

}
