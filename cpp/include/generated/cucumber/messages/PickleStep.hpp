#ifndef CUCUMBER_MESSAGES_PICKLE_STEP_HPP
#define CUCUMBER_MESSAGES_PICKLE_STEP_HPP

#include "cucumber/messages/PickleStepArgument.hpp"
#include "cucumber/messages/PickleStepType.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the PickleStep message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // An executable step
    //
    // Generated code

    struct PickleStep
    {
        std::optional<std::shared_ptr<PickleStepArgument>> argument;
        std::vector<std::string> astNodeIds;
        std::string id;
        std::optional<PickleStepType> type;
        std::string text;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const PickleStep& msg);

    void to_json(nlohmann::json& json, const PickleStep& msg);
    void from_json(const nlohmann::json& json, PickleStep& msg);
}

#endif
