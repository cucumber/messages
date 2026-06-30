
#include "cucumber/messages/test_run_started.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string test_run_started::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "timestamp=", timestamp);
        cucumber::messages::to_string(oss, ", id=", id);

        return oss.str();
    }

    void test_run_started::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("timestamp"), timestamp);
        cucumber::messages::to_json(json, camelize("id"), id);
    }

    void test_run_started::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("timestamp"), timestamp);
        cucumber::messages::from_json(json, camelize("id"), id);
    }

    std::string test_run_started::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const test_run_started& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const test_run_started& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, test_run_started& msg)
    {
        msg.from_json(json);
    }
}
