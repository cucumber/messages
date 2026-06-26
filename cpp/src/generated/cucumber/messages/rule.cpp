
#include "cucumber/messages/rule.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string rule::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", tags=", tags);
        cucumber::messages::to_string(oss, ", keyword=", keyword);
        cucumber::messages::to_string(oss, ", name=", name);
        cucumber::messages::to_string(oss, ", description=", description);
        cucumber::messages::to_string(oss, ", children=", children);
        cucumber::messages::to_string(oss, ", id=", id);

        return oss.str();
    }

    void rule::to_json(nlohmann::json& json) const
    {
        json[camelize("location")] = location;
        json[camelize("tags")] = tags;
        json[camelize("keyword")] = keyword;
        json[camelize("name")] = name;
        json[camelize("description")] = description;
        json[camelize("children")] = children;
        json[camelize("id")] = id;
    }

    void rule::from_json(const nlohmann::json& json)
    {
        json.at(camelize("location")).get_to(location);
        json.at(camelize("tags")).get_to(tags);
        json.at(camelize("keyword")).get_to(keyword);
        json.at(camelize("name")).get_to(name);
        json.at(camelize("description")).get_to(description);
        json.at(camelize("children")).get_to(children);
        json.at(camelize("id")).get_to(id);
    }

    std::string rule::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const rule& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const rule& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, rule& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<rule>& msg)
    {
        msg = std::make_shared<rule>();
        msg->from_json(json);
    }
}
