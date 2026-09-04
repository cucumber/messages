#include "cucumber/messages/TestRunHookStarted.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string TestRunHookStarted::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "id=", id);
        cucumber::messages::to_string(oss, ", testRunStartedId=", testRunStartedId);
        cucumber::messages::to_string(oss, ", hookId=", hookId);
        cucumber::messages::to_string(oss, ", workerId=", workerId);
        cucumber::messages::to_string(oss, ", timestamp=", timestamp);

        return oss.str();
    }

    void TestRunHookStarted::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "id", id);
        cucumber::messages::to_json(json, "testRunStartedId", testRunStartedId);
        cucumber::messages::to_json(json, "hookId", hookId);
        cucumber::messages::to_json(json, "workerId", workerId);
        cucumber::messages::to_json(json, "timestamp", timestamp);
    }

    void TestRunHookStarted::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "id", id);
        cucumber::messages::from_json(json, "testRunStartedId", testRunStartedId);
        cucumber::messages::from_json(json, "hookId", hookId);
        cucumber::messages::from_json(json, "workerId", workerId);
        cucumber::messages::from_json(json, "timestamp", timestamp);
    }

    std::string TestRunHookStarted::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const TestRunHookStarted& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const TestRunHookStarted& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, TestRunHookStarted& msg)
    {
        msg.from_json(json);
    }
}
