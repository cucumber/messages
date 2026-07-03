#include "cucumber/messages/TestRunHookFinished.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string TestRunHookFinished::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "testRunHookStartedId=", testRunHookStartedId);
        cucumber::messages::to_string(oss, ", result=", result);
        cucumber::messages::to_string(oss, ", timestamp=", timestamp);

        return oss.str();
    }

    void TestRunHookFinished::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "testRunHookStartedId", testRunHookStartedId);
        cucumber::messages::to_json(json, "result", result);
        cucumber::messages::to_json(json, "timestamp", timestamp);
    }

    void TestRunHookFinished::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "testRunHookStartedId", testRunHookStartedId);
        cucumber::messages::from_json(json, "result", result);
        cucumber::messages::from_json(json, "timestamp", timestamp);
    }

    std::string TestRunHookFinished::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const TestRunHookFinished& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const TestRunHookFinished& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, TestRunHookFinished& msg)
    {
        msg.from_json(json);
    }
}
