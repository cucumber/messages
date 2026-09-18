#include "cucumber/messages/StepDefinition.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string StepDefinition::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "id=", id);
        cucumber::messages::to_string(oss, ", pattern=", pattern);
        cucumber::messages::to_string(oss, ", sourceReference=", sourceReference);

        return oss.str();
    }

    void StepDefinition::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "id", id);
        cucumber::messages::to_json(json, "pattern", pattern);
        cucumber::messages::to_json(json, "sourceReference", sourceReference);
    }

    void StepDefinition::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "id", id);
        cucumber::messages::from_json(json, "pattern", pattern);
        cucumber::messages::from_json(json, "sourceReference", sourceReference);
    }

    std::string StepDefinition::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const StepDefinition& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const StepDefinition& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, StepDefinition& msg)
    {
        msg.from_json(json);
    }
}
