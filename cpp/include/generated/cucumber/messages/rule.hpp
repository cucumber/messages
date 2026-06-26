#ifndef CUCUMBER_MESSAGES_RULE_HPP
#define CUCUMBER_MESSAGES_RULE_HPP

#include "cucumber/messages/rule_child.hpp"
#include "cucumber/messages/location.hpp"
#include "cucumber/messages/tag.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

namespace cucumber::messages
{
    //
    // Represents the Rule message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct rule
    {
        using shared_ptr = rule;//std::shared_ptr<rule>;

        cucumber::messages::location::shared_ptr location;
        std::vector<cucumber::messages::tag::shared_ptr> tags;
        std::string keyword;
        std::string name;
        std::string description;
        std::vector<cucumber::messages::rule_child::shared_ptr> children;
        std::string id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const rule& msg);

    void to_json(nlohmann::json& json, const rule& msg);
    void from_json(const nlohmann::json& json, rule& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<rule>& msg);

}

#endif
