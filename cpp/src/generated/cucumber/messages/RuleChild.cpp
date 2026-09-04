#include "cucumber/messages/RuleChild.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string RuleChild::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "background=", background);
        cucumber::messages::to_string(oss, ", scenario=", scenario);

        return oss.str();
    }

    void RuleChild::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "background", background);
        cucumber::messages::to_json(json, "scenario", scenario);
    }

    void RuleChild::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "background", background);
        cucumber::messages::from_json(json, "scenario", scenario);
    }

    std::string RuleChild::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const RuleChild& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const RuleChild& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, RuleChild& msg)
    {
        msg.from_json(json);
    }
}
