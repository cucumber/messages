#include "cucumber/messages/PickleStep.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string PickleStep::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "argument=", argument);
        cucumber::messages::to_string(oss, ", astNodeIds=", astNodeIds);
        cucumber::messages::to_string(oss, ", id=", id);
        cucumber::messages::to_string(oss, ", type=", type);
        cucumber::messages::to_string(oss, ", text=", text);

        return oss.str();
    }

    void PickleStep::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "argument", argument);
        cucumber::messages::to_json(json, "astNodeIds", astNodeIds);
        cucumber::messages::to_json(json, "id", id);
        cucumber::messages::to_json(json, "type", type);
        cucumber::messages::to_json(json, "text", text);
    }

    void PickleStep::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "argument", argument);
        cucumber::messages::from_json(json, "astNodeIds", astNodeIds);
        cucumber::messages::from_json(json, "id", id);
        cucumber::messages::from_json(json, "type", type);
        cucumber::messages::from_json(json, "text", text);
    }

    std::string PickleStep::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const PickleStep& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const PickleStep& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, PickleStep& msg)
    {
        msg.from_json(json);
    }
}
