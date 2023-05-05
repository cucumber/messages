#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/duration.hpp>
#include <cucumber/messages/test_step_result_status.hpp>
#include <cucumber/messages/exception.hpp>

namespace cucumber::messages {

//
// Represents the TestStepResult message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct test_step_result : cucumber::message
{
    cucumber::messages::duration duration;
    std::string message;
    cucumber::messages::test_step_result_status status;
    cucumber::messages::exception exception;

    std::string to_string() const;
};

}
