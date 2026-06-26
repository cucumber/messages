
#include "cucumber/messages/tag.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string tag::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", name=", name);
        cucumber::messages::to_string(oss, ", id=", id);

        return oss.str();
    }

    void tag::to_json(nlohmann::json& json) const
    {
        json[camelize("location")] = location;
        json[camelize("name")] = name;
        json[camelize("id")] = id;
    }

    void tag::from_json(const nlohmann::json& json)
    {
        json.at(camelize("location")).get_to(location);
        json.at(camelize("name")).get_to(name);
        json.at(camelize("id")).get_to(id);
    }

    std::string tag::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const tag& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const tag& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, tag& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<tag>& msg)
    {
        msg = std::make_shared<tag>();
        msg->from_json(json);
    }
}
