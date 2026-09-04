#include "cucumber/messages/StepMatchArgumentsList.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string StepMatchArgumentsList::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "stepMatchArguments=", stepMatchArguments);

        return oss.str();
    }

    void StepMatchArgumentsList::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "stepMatchArguments", stepMatchArguments);
    }

    void StepMatchArgumentsList::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "stepMatchArguments", stepMatchArguments);
    }

    std::string StepMatchArgumentsList::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const StepMatchArgumentsList& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const StepMatchArgumentsList& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, StepMatchArgumentsList& msg)
    {
        msg.from_json(json);
    }
}
