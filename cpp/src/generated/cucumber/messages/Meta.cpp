#include "cucumber/messages/Meta.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string Meta::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "protocolVersion=", protocolVersion);
        cucumber::messages::to_string(oss, ", implementation=", implementation);
        cucumber::messages::to_string(oss, ", runtime=", runtime);
        cucumber::messages::to_string(oss, ", os=", os);
        cucumber::messages::to_string(oss, ", cpu=", cpu);
        cucumber::messages::to_string(oss, ", ci=", ci);

        return oss.str();
    }

    void Meta::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "protocolVersion", protocolVersion);
        cucumber::messages::to_json(json, "implementation", implementation);
        cucumber::messages::to_json(json, "runtime", runtime);
        cucumber::messages::to_json(json, "os", os);
        cucumber::messages::to_json(json, "cpu", cpu);
        cucumber::messages::to_json(json, "ci", ci);
    }

    void Meta::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "protocolVersion", protocolVersion);
        cucumber::messages::from_json(json, "implementation", implementation);
        cucumber::messages::from_json(json, "runtime", runtime);
        cucumber::messages::from_json(json, "os", os);
        cucumber::messages::from_json(json, "cpu", cpu);
        cucumber::messages::from_json(json, "ci", ci);
    }

    std::string Meta::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const Meta& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const Meta& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, Meta& msg)
    {
        msg.from_json(json);
    }
}
