
#include "cucumber/messages/background.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string background::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", keyword=", keyword);
        cucumber::messages::to_string(oss, ", name=", name);
        cucumber::messages::to_string(oss, ", description=", description);
        cucumber::messages::to_string(oss, ", steps=", steps);
        cucumber::messages::to_string(oss, ", id=", id);

        return oss.str();
    }

    void background::to_json(nlohmann::json& json) const
    {
        json[camelize("location")] = location;
        json[camelize("keyword")] = keyword;
        json[camelize("name")] = name;
        json[camelize("description")] = description;
        json[camelize("steps")] = steps;
        json[camelize("id")] = id;
    }

    void background::from_json(const nlohmann::json& json)
    {
        json.at(camelize("location")).get_to(location);
        json.at(camelize("keyword")).get_to(keyword);
        json.at(camelize("name")).get_to(name);
        json.at(camelize("description")).get_to(description);
        json.at(camelize("steps")).get_to(steps);
        json.at(camelize("id")).get_to(id);
    }

    std::string background::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const background& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const background& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, background& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<background>& msg)
    {
        msg = std::make_shared<background>();
        msg->from_json(json);
    }
}
