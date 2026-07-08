
#include "cucumber/messages/test_run_hook_finished.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string test_run_hook_finished::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "test_run_hook_started_id=", test_run_hook_started_id);
        cucumber::messages::to_string(oss, ", result=", result);
        cucumber::messages::to_string(oss, ", timestamp=", timestamp);

        return oss.str();
    }

    void test_run_hook_finished::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("test_run_hook_started_id"), test_run_hook_started_id);
        cucumber::messages::to_json(json, camelize("result"), result);
        cucumber::messages::to_json(json, camelize("timestamp"), timestamp);
    }

    void test_run_hook_finished::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("test_run_hook_started_id"), test_run_hook_started_id);
        cucumber::messages::from_json(json, camelize("result"), result);
        cucumber::messages::from_json(json, camelize("timestamp"), timestamp);
    }

    std::string test_run_hook_finished::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const test_run_hook_finished& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const test_run_hook_finished& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, test_run_hook_finished& msg)
    {
        msg.from_json(json);
    }
}
