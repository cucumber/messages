#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/timestamp.hpp>

namespace cucumber::messages {

//
// Represents the TestCaseFinished message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct test_case_finished : cucumber::message
{
    std::string test_case_started_id;
    cucumber::messages::timestamp timestamp;
    bool will_be_retried;

    std::string to_string() const;
};

}
