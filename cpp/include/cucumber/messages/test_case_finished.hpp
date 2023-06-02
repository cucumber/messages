#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/timestamp.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

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

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const test_case_finished& msg);

void to_json(json& j, const test_case_finished& m);

}
