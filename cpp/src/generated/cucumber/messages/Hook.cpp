#include "cucumber/messages/Hook.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string Hook::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "id=", id);
        cucumber::messages::to_string(oss, ", name=", name);
        cucumber::messages::to_string(oss, ", sourceReference=", sourceReference);
        cucumber::messages::to_string(oss, ", tagExpression=", tagExpression);
        cucumber::messages::to_string(oss, ", type=", type);

        return oss.str();
    }

    void Hook::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "id", id);
        cucumber::messages::to_json(json, "name", name);
        cucumber::messages::to_json(json, "sourceReference", sourceReference);
        cucumber::messages::to_json(json, "tagExpression", tagExpression);
        cucumber::messages::to_json(json, "type", type);
    }

    void Hook::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "id", id);
        cucumber::messages::from_json(json, "name", name);
        cucumber::messages::from_json(json, "sourceReference", sourceReference);
        cucumber::messages::from_json(json, "tagExpression", tagExpression);
        cucumber::messages::from_json(json, "type", type);
    }

    std::string Hook::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const Hook& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const Hook& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, Hook& msg)
    {
        msg.from_json(json);
    }
}
