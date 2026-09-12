#include "cucumber/messages/TestCaseFinished.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string TestCaseFinished::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "testCaseStartedId=", testCaseStartedId);
        cucumber::messages::to_string(oss, ", timestamp=", timestamp);
        cucumber::messages::to_string(oss, ", willBeRetried=", willBeRetried);

        return oss.str();
    }

    void TestCaseFinished::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "testCaseStartedId", testCaseStartedId);
        cucumber::messages::to_json(json, "timestamp", timestamp);
        cucumber::messages::to_json(json, "willBeRetried", willBeRetried);
    }

    void TestCaseFinished::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "testCaseStartedId", testCaseStartedId);
        cucumber::messages::from_json(json, "timestamp", timestamp);
        cucumber::messages::from_json(json, "willBeRetried", willBeRetried);
    }

    std::string TestCaseFinished::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const TestCaseFinished& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const TestCaseFinished& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, TestCaseFinished& msg)
    {
        msg.from_json(json);
    }
}
