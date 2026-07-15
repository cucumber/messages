#ifndef CUCUMBER_MESSAGES_FEATURE_CHILD_HPP
#define CUCUMBER_MESSAGES_FEATURE_CHILD_HPP

#include "cucumber/messages/background.hpp"
#include "cucumber/messages/rule.hpp"
#include "cucumber/messages/scenario.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the FeatureChild message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A child node of a `Feature` node
    //
    // Generated code

    struct feature_child
    {
        std::optional<cucumber::messages::rule> rule;
        std::optional<cucumber::messages::background> background;
        std::optional<cucumber::messages::scenario> scenario;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const feature_child& msg);

    void to_json(nlohmann::json& json, const feature_child& msg);
    void from_json(const nlohmann::json& json, feature_child& msg);
}

#endif
