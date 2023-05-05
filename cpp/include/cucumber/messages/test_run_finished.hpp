#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/timestamp.hpp>
#include <cucumber/messages/exception.hpp>

namespace cucumber::messages {

//
// Represents the TestRunFinished message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct test_run_finished : cucumber::message
{
    std::string message;
    bool success;
    cucumber::messages::timestamp timestamp;
    cucumber::messages::exception exception;

    std::string to_string() const;
};

}
