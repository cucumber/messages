#include "cucumber/messages/TestCase.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string TestCase::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "id=", id);
        cucumber::messages::to_string(oss, ", pickleId=", pickleId);
        cucumber::messages::to_string(oss, ", testSteps=", testSteps);
        cucumber::messages::to_string(oss, ", testRunStartedId=", testRunStartedId);

        return oss.str();
    }

    void TestCase::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "id", id);
        cucumber::messages::to_json(json, "pickleId", pickleId);
        cucumber::messages::to_json(json, "testSteps", testSteps);
        cucumber::messages::to_json(json, "testRunStartedId", testRunStartedId);
    }

    void TestCase::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "id", id);
        cucumber::messages::from_json(json, "pickleId", pickleId);
        cucumber::messages::from_json(json, "testSteps", testSteps);
        cucumber::messages::from_json(json, "testRunStartedId", testRunStartedId);
    }

    std::string TestCase::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const TestCase& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const TestCase& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, TestCase& msg)
    {
        msg.from_json(json);
    }
}
