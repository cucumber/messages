
#include "cucumber/messages/meta.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string meta::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "protocol_version=", protocol_version);
        cucumber::messages::to_string(oss, ", implementation=", implementation);
        cucumber::messages::to_string(oss, ", runtime=", runtime);
        cucumber::messages::to_string(oss, ", os=", os);
        cucumber::messages::to_string(oss, ", cpu=", cpu);
        cucumber::messages::to_string(oss, ", ci=", ci);

        return oss.str();
    }

    void meta::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("protocol_version"), protocol_version);
        cucumber::messages::to_json(json, camelize("implementation"), implementation);
        cucumber::messages::to_json(json, camelize("runtime"), runtime);
        cucumber::messages::to_json(json, camelize("os"), os);
        cucumber::messages::to_json(json, camelize("cpu"), cpu);
        cucumber::messages::to_json(json, camelize("ci"), ci);
    }

    void meta::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("protocol_version"), protocol_version);
        cucumber::messages::from_json(json, camelize("implementation"), implementation);
        cucumber::messages::from_json(json, camelize("runtime"), runtime);
        cucumber::messages::from_json(json, camelize("os"), os);
        cucumber::messages::from_json(json, camelize("cpu"), cpu);
        cucumber::messages::from_json(json, camelize("ci"), ci);
    }

    std::string meta::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const meta& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const meta& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, meta& msg)
    {
        msg.from_json(json);
    }
}
