#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/timestamp.hpp>
#include <cucumber/messages/exception.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the TestRunFinished message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct test_run_finished
{
    std::optional<std::string> message;
    bool success;
    cucumber::messages::timestamp timestamp;
    std::optional<cucumber::messages::exception> exception;
    std::optional<std::string> test_run_started_id;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const test_run_finished& msg);

void to_json(json& j, const test_run_finished& m);

}
