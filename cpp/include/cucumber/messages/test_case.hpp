#pragma once

#include <vector>
#include <string>

#include <cucumber/messages/test_step.hpp>

namespace cucumber::messages {

//
// Represents the TestCase message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// //// TestCases
//
// A `TestCase` contains a sequence of `TestStep`s.
//
// Generated code

struct test_case
{
    std::string id;
    std::string pickle_id;
    std::vector<cucumber::messages::test_step> test_steps;

    std::string to_string() const;
};

std::ostream&
operator<<(std::ostream& os, const test_case& msg);

}
