#ifndef CUCUMBER_MESSAGES_RULE_CHILD_HPP
#define CUCUMBER_MESSAGES_RULE_CHILD_HPP

#include "cucumber/messages/Background.hpp"
#include "cucumber/messages/Scenario.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the RuleChild message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A child node of a `Rule` node
    //
    // Generated code

    struct RuleChild
    {
        std::optional<std::shared_ptr<Background>> background;
        std::optional<std::shared_ptr<Scenario>> scenario;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const RuleChild& msg);

    void to_json(nlohmann::json& json, const RuleChild& msg);
    void from_json(const nlohmann::json& json, RuleChild& msg);
}

#endif
