#include "cucumber/messages/TestStep.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string TestStep::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "hookId=", hookId);
        cucumber::messages::to_string(oss, ", id=", id);
        cucumber::messages::to_string(oss, ", pickleStepId=", pickleStepId);
        cucumber::messages::to_string(oss, ", stepDefinitionIds=", stepDefinitionIds);
        cucumber::messages::to_string(oss, ", stepMatchArgumentsLists=", stepMatchArgumentsLists);

        return oss.str();
    }

    void TestStep::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "hookId", hookId);
        cucumber::messages::to_json(json, "id", id);
        cucumber::messages::to_json(json, "pickleStepId", pickleStepId);
        cucumber::messages::to_json(json, "stepDefinitionIds", stepDefinitionIds);
        cucumber::messages::to_json(json, "stepMatchArgumentsLists", stepMatchArgumentsLists);
    }

    void TestStep::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "hookId", hookId);
        cucumber::messages::from_json(json, "id", id);
        cucumber::messages::from_json(json, "pickleStepId", pickleStepId);
        cucumber::messages::from_json(json, "stepDefinitionIds", stepDefinitionIds);
        cucumber::messages::from_json(json, "stepMatchArgumentsLists", stepMatchArgumentsLists);
    }

    std::string TestStep::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const TestStep& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const TestStep& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, TestStep& msg)
    {
        msg.from_json(json);
    }
}
