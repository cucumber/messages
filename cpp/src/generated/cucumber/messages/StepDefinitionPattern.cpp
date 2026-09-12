#include "cucumber/messages/StepDefinitionPattern.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string StepDefinitionPattern::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "source=", source);
        cucumber::messages::to_string(oss, ", type=", type);

        return oss.str();
    }

    void StepDefinitionPattern::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "source", source);
        cucumber::messages::to_json(json, "type", type);
    }

    void StepDefinitionPattern::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "source", source);
        cucumber::messages::from_json(json, "type", type);
    }

    std::string StepDefinitionPattern::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const StepDefinitionPattern& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const StepDefinitionPattern& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, StepDefinitionPattern& msg)
    {
        msg.from_json(json);
    }
}
