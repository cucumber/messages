#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/test_step_result.hpp>
#include <cucumber/messages/timestamp.hpp>

namespace cucumber::messages {

//
// Represents the TestStepFinished message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct test_step_finished
{
    std::string test_case_started_id;
    std::string test_step_id;
    cucumber::messages::test_step_result test_step_result;
    cucumber::messages::timestamp timestamp;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const test_step_finished& msg);

using json = nlohmann::json;

void to_json(json& j, const test_step_finished& m);

}
