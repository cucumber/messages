
#include "cucumber/messages/feature.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string feature::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", tags=", tags);
        cucumber::messages::to_string(oss, ", language=", language);
        cucumber::messages::to_string(oss, ", keyword=", keyword);
        cucumber::messages::to_string(oss, ", name=", name);
        cucumber::messages::to_string(oss, ", description=", description);
        cucumber::messages::to_string(oss, ", children=", children);

        return oss.str();
    }

    void feature::to_json(nlohmann::json& json) const
    {
        json[camelize("location")] = location;
        json[camelize("tags")] = tags;
        json[camelize("language")] = language;
        json[camelize("keyword")] = keyword;
        json[camelize("name")] = name;
        json[camelize("description")] = description;
        json[camelize("children")] = children;
    }

    void feature::from_json(const nlohmann::json& json)
    {
        json.at(camelize("location")).get_to(location);
        json.at(camelize("tags")).get_to(tags);
        json.at(camelize("language")).get_to(language);
        json.at(camelize("keyword")).get_to(keyword);
        json.at(camelize("name")).get_to(name);
        json.at(camelize("description")).get_to(description);
        json.at(camelize("children")).get_to(children);
    }

    std::string feature::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const feature& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const feature& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, feature& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<feature>& msg)
    {
        msg = std::make_shared<feature>();
        msg->from_json(json);
    }
}
