
#include "cucumber/messages/feature.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
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
        cucumber::messages::to_json(json, camelize("location"), location);
        cucumber::messages::to_json(json, camelize("tags"), tags);
        cucumber::messages::to_json(json, camelize("language"), language);
        cucumber::messages::to_json(json, camelize("keyword"), keyword);
        cucumber::messages::to_json(json, camelize("name"), name);
        cucumber::messages::to_json(json, camelize("description"), description);
        cucumber::messages::to_json(json, camelize("children"), children);
    }

    void feature::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("location"), location);
        cucumber::messages::from_json(json, camelize("tags"), tags);
        cucumber::messages::from_json(json, camelize("language"), language);
        cucumber::messages::from_json(json, camelize("keyword"), keyword);
        cucumber::messages::from_json(json, camelize("name"), name);
        cucumber::messages::from_json(json, camelize("description"), description);
        cucumber::messages::from_json(json, camelize("children"), children);
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
}
