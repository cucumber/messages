#include "cucumber/messages/TestCaseStarted.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string TestCaseStarted::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "attempt=", attempt);
        cucumber::messages::to_string(oss, ", id=", id);
        cucumber::messages::to_string(oss, ", testCaseId=", testCaseId);
        cucumber::messages::to_string(oss, ", workerId=", workerId);
        cucumber::messages::to_string(oss, ", timestamp=", timestamp);

        return oss.str();
    }

    void TestCaseStarted::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "attempt", attempt);
        cucumber::messages::to_json(json, "id", id);
        cucumber::messages::to_json(json, "testCaseId", testCaseId);
        cucumber::messages::to_json(json, "workerId", workerId);
        cucumber::messages::to_json(json, "timestamp", timestamp);
    }

    void TestCaseStarted::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "attempt", attempt);
        cucumber::messages::from_json(json, "id", id);
        cucumber::messages::from_json(json, "testCaseId", testCaseId);
        cucumber::messages::from_json(json, "workerId", workerId);
        cucumber::messages::from_json(json, "timestamp", timestamp);
    }

    std::string TestCaseStarted::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const TestCaseStarted& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const TestCaseStarted& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, TestCaseStarted& msg)
    {
        msg.from_json(json);
    }
}
