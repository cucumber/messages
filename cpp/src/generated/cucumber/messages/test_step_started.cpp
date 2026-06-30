
#include "cucumber/messages/test_step_started.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string test_step_started::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "test_case_started_id=", test_case_started_id);
        cucumber::messages::to_string(oss, ", test_step_id=", test_step_id);
        cucumber::messages::to_string(oss, ", timestamp=", timestamp);

        return oss.str();
    }

    void test_step_started::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("test_case_started_id"), test_case_started_id);
        cucumber::messages::to_json(json, camelize("test_step_id"), test_step_id);
        cucumber::messages::to_json(json, camelize("timestamp"), timestamp);
    }

    void test_step_started::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("test_case_started_id"), test_case_started_id);
        cucumber::messages::from_json(json, camelize("test_step_id"), test_step_id);
        cucumber::messages::from_json(json, camelize("timestamp"), timestamp);
    }

    std::string test_step_started::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const test_step_started& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const test_step_started& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, test_step_started& msg)
    {
        msg.from_json(json);
    }
}
