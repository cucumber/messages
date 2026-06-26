
#include "cucumber/messages/test_step_finished.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string test_step_finished::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "test_case_started_id=", test_case_started_id);
        cucumber::messages::to_string(oss, ", test_step_id=", test_step_id);
        cucumber::messages::to_string(oss, ", test_step_result=", test_step_result);
        cucumber::messages::to_string(oss, ", timestamp=", timestamp);

        return oss.str();
    }

    void test_step_finished::to_json(nlohmann::json& json) const
    {
        json[camelize("test_case_started_id")] = test_case_started_id;
        json[camelize("test_step_id")] = test_step_id;
        json[camelize("test_step_result")] = test_step_result;
        json[camelize("timestamp")] = timestamp;
    }

    void test_step_finished::from_json(const nlohmann::json& json)
    {
        json.at(camelize("test_case_started_id")).get_to(test_case_started_id);
        json.at(camelize("test_step_id")).get_to(test_step_id);
        json.at(camelize("test_step_result")).get_to(test_step_result);
        json.at(camelize("timestamp")).get_to(timestamp);
    }

    std::string test_step_finished::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const test_step_finished& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const test_step_finished& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, test_step_finished& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<test_step_finished>& msg)
    {
        msg = std::make_shared<test_step_finished>();
        msg->from_json(json);
    }
}
