
#include "cucumber/messages/group.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string group::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "children=", children);
        cucumber::messages::to_string(oss, ", start=", start);
        cucumber::messages::to_string(oss, ", value=", value);

        return oss.str();
    }

    void group::to_json(nlohmann::json& json) const
    {
        if (children.has_value())
        {
            json[camelize("children")] = children;
        }
        if (start.has_value())
        {
            json[camelize("start")] = start;
        }
        if (value.has_value())
        {
            json[camelize("value")] = value;
        }
    }

    void group::from_json(const nlohmann::json& json)
    {
        if (children.has_value())
        {
            json.at(camelize("children")).get_to(children.emplace());
        }
        if (start.has_value())
        {
            json.at(camelize("start")).get_to(start.emplace());
        }
        if (value.has_value())
        {
            json.at(camelize("value")).get_to(value.emplace());
        }
    }

    std::string group::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const group& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const group& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, group& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<group>& msg)
    {
        msg = std::make_shared<group>();
        msg->from_json(json);
    }
}
