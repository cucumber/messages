#include "cucumber/messages/StepMatchArgument.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string StepMatchArgument::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "group=", group);
        cucumber::messages::to_string(oss, ", parameterTypeName=", parameterTypeName);

        return oss.str();
    }

    void StepMatchArgument::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "group", group);
        cucumber::messages::to_json(json, "parameterTypeName", parameterTypeName);
    }

    void StepMatchArgument::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "group", group);
        cucumber::messages::from_json(json, "parameterTypeName", parameterTypeName);
    }

    std::string StepMatchArgument::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const StepMatchArgument& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const StepMatchArgument& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, StepMatchArgument& msg)
    {
        msg.from_json(json);
    }
}
