
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
        cucumber::messages::to_json(json, camelize("location"), location);
        cucumber::messages::to_json(json, camelize("tags"), tags);
        cucumber::messages::to_json(json, camelize("keyword"), keyword);
        cucumber::messages::to_json(json, camelize("name"), name);
        cucumber::messages::to_json(json, camelize("description"), description);
        cucumber::messages::to_json(json, camelize("children"), children);
        cucumber::messages::to_json(json, camelize("id"), id);
    }

    void rule::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("location"), location);
        cucumber::messages::from_json(json, camelize("tags"), tags);
        cucumber::messages::from_json(json, camelize("keyword"), keyword);
        cucumber::messages::from_json(json, camelize("name"), name);
        cucumber::messages::from_json(json, camelize("description"), description);
        cucumber::messages::from_json(json, camelize("children"), children);
        cucumber::messages::from_json(json, camelize("id"), id);
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
}
