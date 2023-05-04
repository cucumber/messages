#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/location.hpp>
#include <cucumber/messages/step.hpp>

namespace cucumber::messages {

//
// Represents the Background message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// Generated code

struct background : cucumber::message
{
    cucumber::messages::location location;
    std::string keyword;
    std::string name;
    std::string description;
    std::vector<cucumber::messages::step> steps;
    std::string id;

    std::string to_string() const override;
};

}
