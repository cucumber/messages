#ifndef CUCUMBER_MESSAGES_FEATURE_CHILD_HPP
#define CUCUMBER_MESSAGES_FEATURE_CHILD_HPP

#include "cucumber/messages/Background.hpp"
#include "cucumber/messages/Rule.hpp"
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
    // Represents the FeatureChild message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A child node of a `Feature` node
    //
    // Generated code

    struct FeatureChild
    {
        std::optional<std::shared_ptr<Rule>> rule;
        std::optional<std::shared_ptr<Background>> background;
        std::optional<std::shared_ptr<Scenario>> scenario;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const FeatureChild& msg);

    void to_json(nlohmann::json& json, const FeatureChild& msg);
    void from_json(const nlohmann::json& json, FeatureChild& msg);
}

#endif
