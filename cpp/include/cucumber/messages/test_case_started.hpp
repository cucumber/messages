#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/timestamp.hpp>

namespace cucumber::messages {

//
// Represents the TestCaseStarted message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct test_case_started : cucumber::message
{
    std::size_t attempt;
    std::string id;
    std::string test_case_id;
    std::string worker_id;
    cucumber::messages::timestamp timestamp;

    std::string to_string() const override;
};

}
