#ifndef CUCUMBER_MESSAGES_RULE_CHILD_HPP
#define CUCUMBER_MESSAGES_RULE_CHILD_HPP

#include "cucumber/messages/background.hpp"
#include "cucumber/messages/scenario.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the RuleChild message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A child node of a `Rule` node
    //
    // Generated code

    struct rule_child
    {
        std::optional<cucumber::messages::background> background;
        std::optional<cucumber::messages::scenario> scenario;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const rule_child& msg);

    void to_json(nlohmann::json& json, const rule_child& msg);
    void from_json(const nlohmann::json& json, rule_child& msg);
}

#endif
