#ifndef CUCUMBER_MESSAGES_STEP_MATCH_ARGUMENTS_LIST_HPP
#define CUCUMBER_MESSAGES_STEP_MATCH_ARGUMENTS_LIST_HPP

#include "cucumber/messages/StepMatchArgument.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <ostream>
#include <string>
#include <vector>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the StepMatchArgumentsList message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //

    struct StepMatchArgumentsList
    {
        std::vector<std::shared_ptr<StepMatchArgument>> stepMatchArguments;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const StepMatchArgumentsList& msg);

    void to_json(nlohmann::json& json, const StepMatchArgumentsList& msg);
    void from_json(const nlohmann::json& json, StepMatchArgumentsList& msg);
}

#endif
