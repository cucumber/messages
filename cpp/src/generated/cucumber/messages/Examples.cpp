#include "cucumber/messages/Examples.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string Examples::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", tags=", tags);
        cucumber::messages::to_string(oss, ", keyword=", keyword);
        cucumber::messages::to_string(oss, ", name=", name);
        cucumber::messages::to_string(oss, ", description=", description);
        cucumber::messages::to_string(oss, ", tableHeader=", tableHeader);
        cucumber::messages::to_string(oss, ", tableBody=", tableBody);
        cucumber::messages::to_string(oss, ", id=", id);

        return oss.str();
    }

    void Examples::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "location", location);
        cucumber::messages::to_json(json, "tags", tags);
        cucumber::messages::to_json(json, "keyword", keyword);
        cucumber::messages::to_json(json, "name", name);
        cucumber::messages::to_json(json, "description", description);
        cucumber::messages::to_json(json, "tableHeader", tableHeader);
        cucumber::messages::to_json(json, "tableBody", tableBody);
        cucumber::messages::to_json(json, "id", id);
    }

    void Examples::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "location", location);
        cucumber::messages::from_json(json, "tags", tags);
        cucumber::messages::from_json(json, "keyword", keyword);
        cucumber::messages::from_json(json, "name", name);
        cucumber::messages::from_json(json, "description", description);
        cucumber::messages::from_json(json, "tableHeader", tableHeader);
        cucumber::messages::from_json(json, "tableBody", tableBody);
        cucumber::messages::from_json(json, "id", id);
    }

    std::string Examples::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const Examples& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const Examples& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, Examples& msg)
    {
        msg.from_json(json);
    }
}
