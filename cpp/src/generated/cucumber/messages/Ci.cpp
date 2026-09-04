#include "cucumber/messages/Ci.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string Ci::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "name=", name);
        cucumber::messages::to_string(oss, ", url=", url);
        cucumber::messages::to_string(oss, ", buildNumber=", buildNumber);
        cucumber::messages::to_string(oss, ", git=", git);

        return oss.str();
    }

    void Ci::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "name", name);
        cucumber::messages::to_json(json, "url", url);
        cucumber::messages::to_json(json, "buildNumber", buildNumber);
        cucumber::messages::to_json(json, "git", git);
    }

    void Ci::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "name", name);
        cucumber::messages::from_json(json, "url", url);
        cucumber::messages::from_json(json, "buildNumber", buildNumber);
        cucumber::messages::from_json(json, "git", git);
    }

    std::string Ci::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const Ci& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const Ci& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, Ci& msg)
    {
        msg.from_json(json);
    }
}
