#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/timestamp.hpp>

namespace cucumber::messages {

//
// Represents the TestStepStarted message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct test_step_started : cucumber::message
{
    std::string test_case_started_id;
    std::string test_step_id;
    cucumber::messages::timestamp timestamp;

    std::string to_string() const;
};

}
