
#include "cucumber/messages/step_match_argument.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string step_match_argument::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "group=", group);
        cucumber::messages::to_string(oss, ", parameter_type_name=", parameter_type_name);

        return oss.str();
    }

    void step_match_argument::to_json(nlohmann::json& json) const
    {
        json[camelize("group")] = group;
        if (parameter_type_name.has_value())
        {
            json[camelize("parameter_type_name")] = parameter_type_name;
        }
    }

    void step_match_argument::from_json(const nlohmann::json& json)
    {
        json.at(camelize("group")).get_to(group);
        if (parameter_type_name.has_value())
        {
            json.at(camelize("parameter_type_name")).get_to(parameter_type_name.emplace());
        }
    }

    std::string step_match_argument::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const step_match_argument& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const step_match_argument& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, step_match_argument& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<step_match_argument>& msg)
    {
        msg = std::make_shared<step_match_argument>();
        msg->from_json(json);
    }
}
