#include "cucumber/messages/TestStepStarted.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string TestStepStarted::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "testCaseStartedId=", testCaseStartedId);
        cucumber::messages::to_string(oss, ", testStepId=", testStepId);
        cucumber::messages::to_string(oss, ", timestamp=", timestamp);

        return oss.str();
    }

    void TestStepStarted::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "testCaseStartedId", testCaseStartedId);
        cucumber::messages::to_json(json, "testStepId", testStepId);
        cucumber::messages::to_json(json, "timestamp", timestamp);
    }

    void TestStepStarted::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "testCaseStartedId", testCaseStartedId);
        cucumber::messages::from_json(json, "testStepId", testStepId);
        cucumber::messages::from_json(json, "timestamp", timestamp);
    }

    std::string TestStepStarted::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const TestStepStarted& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const TestStepStarted& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, TestStepStarted& msg)
    {
        msg.from_json(json);
    }
}
