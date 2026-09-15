#include "cucumber/messages/TestRunFinished.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string TestRunFinished::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "message=", message);
        cucumber::messages::to_string(oss, ", success=", success);
        cucumber::messages::to_string(oss, ", timestamp=", timestamp);
        cucumber::messages::to_string(oss, ", exception=", exception);
        cucumber::messages::to_string(oss, ", testRunStartedId=", testRunStartedId);

        return oss.str();
    }

    void TestRunFinished::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "message", message);
        cucumber::messages::to_json(json, "success", success);
        cucumber::messages::to_json(json, "timestamp", timestamp);
        cucumber::messages::to_json(json, "exception", exception);
        cucumber::messages::to_json(json, "testRunStartedId", testRunStartedId);
    }

    void TestRunFinished::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "message", message);
        cucumber::messages::from_json(json, "success", success);
        cucumber::messages::from_json(json, "timestamp", timestamp);
        cucumber::messages::from_json(json, "exception", exception);
        cucumber::messages::from_json(json, "testRunStartedId", testRunStartedId);
    }

    std::string TestRunFinished::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const TestRunFinished& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const TestRunFinished& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, TestRunFinished& msg)
    {
        msg.from_json(json);
    }
}
