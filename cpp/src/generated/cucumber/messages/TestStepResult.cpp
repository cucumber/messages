#include "cucumber/messages/TestStepResult.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string TestStepResult::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "duration=", duration);
        cucumber::messages::to_string(oss, ", message=", message);
        cucumber::messages::to_string(oss, ", status=", status);
        cucumber::messages::to_string(oss, ", exception=", exception);

        return oss.str();
    }

    void TestStepResult::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "duration", duration);
        cucumber::messages::to_json(json, "message", message);
        cucumber::messages::to_json(json, "status", status);
        cucumber::messages::to_json(json, "exception", exception);
    }

    void TestStepResult::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "duration", duration);
        cucumber::messages::from_json(json, "message", message);
        cucumber::messages::from_json(json, "status", status);
        cucumber::messages::from_json(json, "exception", exception);
    }

    std::string TestStepResult::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const TestStepResult& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const TestStepResult& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, TestStepResult& msg)
    {
        msg.from_json(json);
    }
}
