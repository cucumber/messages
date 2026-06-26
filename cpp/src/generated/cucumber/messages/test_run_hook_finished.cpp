
#include "cucumber/messages/test_run_hook_finished.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
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
        json[camelize("test_run_hook_started_id")] = test_run_hook_started_id;
        json[camelize("result")] = result;
        json[camelize("timestamp")] = timestamp;
    }

    void test_run_hook_finished::from_json(const nlohmann::json& json)
    {
        json.at(camelize("test_run_hook_started_id")).get_to(test_run_hook_started_id);
        json.at(camelize("result")).get_to(result);
        json.at(camelize("timestamp")).get_to(timestamp);
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

    void from_json(const nlohmann::json& json, std::shared_ptr<test_run_hook_finished>& msg)
    {
        msg = std::make_shared<test_run_hook_finished>();
        msg->from_json(json);
    }
}
