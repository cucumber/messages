
#include "cucumber/messages/test_run_hook_started.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string test_run_hook_started::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "id=", id);
        cucumber::messages::to_string(oss, ", test_run_started_id=", test_run_started_id);
        cucumber::messages::to_string(oss, ", hook_id=", hook_id);
        cucumber::messages::to_string(oss, ", worker_id=", worker_id);
        cucumber::messages::to_string(oss, ", timestamp=", timestamp);

        return oss.str();
    }

    void test_run_hook_started::to_json(nlohmann::json& json) const
    {
        json[camelize("id")] = id;
        json[camelize("test_run_started_id")] = test_run_started_id;
        json[camelize("hook_id")] = hook_id;
        if (worker_id.has_value())
        {
            json[camelize("worker_id")] = worker_id;
        }
        json[camelize("timestamp")] = timestamp;
    }

    void test_run_hook_started::from_json(const nlohmann::json& json)
    {
        json.at(camelize("id")).get_to(id);
        json.at(camelize("test_run_started_id")).get_to(test_run_started_id);
        json.at(camelize("hook_id")).get_to(hook_id);
        if (worker_id.has_value())
        {
            json.at(camelize("worker_id")).get_to(worker_id.emplace());
        }
        json.at(camelize("timestamp")).get_to(timestamp);
    }

    std::string test_run_hook_started::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const test_run_hook_started& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const test_run_hook_started& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, test_run_hook_started& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<test_run_hook_started>& msg)
    {
        msg = std::make_shared<test_run_hook_started>();
        msg->from_json(json);
    }
}
