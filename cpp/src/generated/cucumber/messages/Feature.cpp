#include "cucumber/messages/Feature.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string Feature::to_string() const
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

    void Feature::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "location", location);
        cucumber::messages::to_json(json, "tags", tags);
        cucumber::messages::to_json(json, "language", language);
        cucumber::messages::to_json(json, "keyword", keyword);
        cucumber::messages::to_json(json, "name", name);
        cucumber::messages::to_json(json, "description", description);
        cucumber::messages::to_json(json, "children", children);
    }

    void Feature::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "location", location);
        cucumber::messages::from_json(json, "tags", tags);
        cucumber::messages::from_json(json, "language", language);
        cucumber::messages::from_json(json, "keyword", keyword);
        cucumber::messages::from_json(json, "name", name);
        cucumber::messages::from_json(json, "description", description);
        cucumber::messages::from_json(json, "children", children);
    }

    std::string Feature::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const Feature& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const Feature& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, Feature& msg)
    {
        msg.from_json(json);
    }
}
