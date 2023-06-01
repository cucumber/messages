#pragma once

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#include <cucumber/messages/duration.hpp>
#include <cucumber/messages/test_step_result_status.hpp>
#include <cucumber/messages/exception.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the TestStepResult message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct test_step_result
{
    cucumber::messages::duration duration;
    std::optional<std::string> message;
    cucumber::messages::test_step_result_status status;
    std::optional<cucumber::messages::exception> exception;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const test_step_result& msg);

void to_json(json& j, const test_step_result& m);

}
