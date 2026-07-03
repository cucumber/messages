#include "cucumber/messages/PickleTag.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string PickleTag::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "name=", name);
        cucumber::messages::to_string(oss, ", astNodeId=", astNodeId);

        return oss.str();
    }

    void PickleTag::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "name", name);
        cucumber::messages::to_json(json, "astNodeId", astNodeId);
    }

    void PickleTag::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "name", name);
        cucumber::messages::from_json(json, "astNodeId", astNodeId);
    }

    std::string PickleTag::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const PickleTag& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const PickleTag& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, PickleTag& msg)
    {
        msg.from_json(json);
    }
}
