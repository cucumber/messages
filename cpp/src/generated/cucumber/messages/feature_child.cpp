
#include "cucumber/messages/feature_child.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string feature_child::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "rule=", rule);
        cucumber::messages::to_string(oss, ", background=", background);
        cucumber::messages::to_string(oss, ", scenario=", scenario);

        return oss.str();
    }

    void feature_child::to_json(nlohmann::json& json) const
    {
        if (rule.has_value())
        {
            json[camelize("rule")] = rule;
        }
        if (background.has_value())
        {
            json[camelize("background")] = background;
        }
        if (scenario.has_value())
        {
            json[camelize("scenario")] = scenario;
        }
    }

    void feature_child::from_json(const nlohmann::json& json)
    {
        if (rule.has_value())
        {
            json.at(camelize("rule")).get_to(rule.emplace());
        }
        if (background.has_value())
        {
            json.at(camelize("background")).get_to(background.emplace());
        }
        if (scenario.has_value())
        {
            json.at(camelize("scenario")).get_to(scenario.emplace());
        }
    }

    std::string feature_child::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const feature_child& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const feature_child& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, feature_child& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<feature_child>& msg)
    {
        msg = std::make_shared<feature_child>();
        msg->from_json(json);
    }
}
