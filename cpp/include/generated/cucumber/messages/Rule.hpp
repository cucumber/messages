#ifndef CUCUMBER_MESSAGES_RULE_HPP
#define CUCUMBER_MESSAGES_RULE_HPP

#include "cucumber/messages/RuleChild.hpp"
#include "cucumber/messages/Location.hpp"
#include "cucumber/messages/Tag.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <ostream>
#include <string>
#include <vector>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Rule message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct Rule
    {
        std::shared_ptr<Location> location;
        std::vector<std::shared_ptr<Tag>> tags;
        std::string keyword;
        std::string name;
        std::string description;
        std::vector<std::shared_ptr<RuleChild>> children;
        std::string id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Rule& msg);

    void to_json(nlohmann::json& json, const Rule& msg);
    void from_json(const nlohmann::json& json, Rule& msg);
}

#endif
