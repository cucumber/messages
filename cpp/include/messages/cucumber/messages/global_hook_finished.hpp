#pragma once

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

#include <cucumber/messages/test_step_result.hpp>
#include <cucumber/messages/timestamp.hpp>

namespace cucumber::messages {

using json = nlohmann::json;

//
// Represents the GlobalHookFinished message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct global_hook_finished
{
    std::string global_hook_started_id;
    cucumber::messages::test_step_result result;
    cucumber::messages::timestamp timestamp;

    std::string to_string() const;

    void to_json(json& j) const;
    std::string to_json() const;
};

std::ostream&
operator<<(std::ostream& os, const global_hook_finished& msg);

void to_json(json& j, const global_hook_finished& m);

}
