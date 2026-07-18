#include "cucumber/messages/TestRunStarted.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string TestRunStarted::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "timestamp=", timestamp);
        cucumber::messages::to_string(oss, ", id=", id);

        return oss.str();
    }

    void TestRunStarted::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "timestamp", timestamp);
        cucumber::messages::to_json(json, "id", id);
    }

    void TestRunStarted::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "timestamp", timestamp);
        cucumber::messages::from_json(json, "id", id);
    }

    std::string TestRunStarted::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const TestRunStarted& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const TestRunStarted& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, TestRunStarted& msg)
    {
        msg.from_json(json);
    }
}
