
#include "cucumber/messages/hook.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string hook::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "id=", id);
        cucumber::messages::to_string(oss, ", name=", name);
        cucumber::messages::to_string(oss, ", source_reference=", source_reference);
        cucumber::messages::to_string(oss, ", tag_expression=", tag_expression);
        cucumber::messages::to_string(oss, ", type=", type);

        return oss.str();
    }

    void hook::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("id"), id);
        cucumber::messages::to_json(json, camelize("name"), name);
        cucumber::messages::to_json(json, camelize("source_reference"), source_reference);
        cucumber::messages::to_json(json, camelize("tag_expression"), tag_expression);
        cucumber::messages::to_json(json, camelize("type"), type);
    }

    void hook::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("id"), id);
        cucumber::messages::from_json(json, camelize("name"), name);
        cucumber::messages::from_json(json, camelize("source_reference"), source_reference);
        cucumber::messages::from_json(json, camelize("tag_expression"), tag_expression);
        cucumber::messages::from_json(json, camelize("type"), type);
    }

    std::string hook::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const hook& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const hook& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, hook& msg)
    {
        msg.from_json(json);
    }
}
