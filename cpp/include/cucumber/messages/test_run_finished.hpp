#pragma once

#include <vector>
#include <string>

#include <cucumber/messages/timestamp.hpp>
#include <cucumber/messages/exception.hpp>

namespace cucumber::messages {

//
// Represents the TestRunFinished message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct test_run_finished
{
    std::string message;
    bool success;
    cucumber::messages::timestamp timestamp;
    cucumber::messages::exception exception;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const test_run_finished& msg);

}
