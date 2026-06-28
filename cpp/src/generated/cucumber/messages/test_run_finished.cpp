
#include "cucumber/messages/test_run_finished.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string test_run_finished::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "message=", message);
        cucumber::messages::to_string(oss, ", success=", success);
        cucumber::messages::to_string(oss, ", timestamp=", timestamp);
        cucumber::messages::to_string(oss, ", exception=", exception);
        cucumber::messages::to_string(oss, ", test_run_started_id=", test_run_started_id);

        return oss.str();
    }

    void test_run_finished::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("message"), message);
        cucumber::messages::to_json(json, camelize("success"), success);
        cucumber::messages::to_json(json, camelize("timestamp"), timestamp);
        cucumber::messages::to_json(json, camelize("exception"), exception);
        cucumber::messages::to_json(json, camelize("test_run_started_id"), test_run_started_id);
    }

    void test_run_finished::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("message"), message);
        cucumber::messages::from_json(json, camelize("success"), success);
        cucumber::messages::from_json(json, camelize("timestamp"), timestamp);
        cucumber::messages::from_json(json, camelize("exception"), exception);
        cucumber::messages::from_json(json, camelize("test_run_started_id"), test_run_started_id);
    }

    std::string test_run_finished::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const test_run_finished& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const test_run_finished& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, test_run_finished& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<test_run_finished>& msg)
    {
        msg = std::make_shared<test_run_finished>();
        msg->from_json(json);
    }
}
