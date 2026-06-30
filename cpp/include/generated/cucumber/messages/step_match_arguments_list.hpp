#ifndef CUCUMBER_MESSAGES_STEP_MATCH_ARGUMENTS_LIST_HPP
#define CUCUMBER_MESSAGES_STEP_MATCH_ARGUMENTS_LIST_HPP

#include "cucumber/messages/step_match_argument.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

namespace cucumber::messages
{
    //
    // Represents the StepMatchArgumentsList message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct step_match_arguments_list
    {
        std::vector<cucumber::messages::step_match_argument> step_match_arguments;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const step_match_arguments_list& msg);

    void to_json(nlohmann::json& json, const step_match_arguments_list& msg);
    void from_json(const nlohmann::json& json, step_match_arguments_list& msg);
}

#endif
