
#include "cucumber/messages/test_case_finished.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string test_case_finished::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "test_case_started_id=", test_case_started_id);
        cucumber::messages::to_string(oss, ", timestamp=", timestamp);
        cucumber::messages::to_string(oss, ", will_be_retried=", will_be_retried);

        return oss.str();
    }

    void test_case_finished::to_json(nlohmann::json& json) const
    {
        json[camelize("test_case_started_id")] = test_case_started_id;
        json[camelize("timestamp")] = timestamp;
        json[camelize("will_be_retried")] = will_be_retried;
    }

    void test_case_finished::from_json(const nlohmann::json& json)
    {
        json.at(camelize("test_case_started_id")).get_to(test_case_started_id);
        json.at(camelize("timestamp")).get_to(timestamp);
        json.at(camelize("will_be_retried")).get_to(will_be_retried);
    }

    std::string test_case_finished::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const test_case_finished& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const test_case_finished& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, test_case_finished& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<test_case_finished>& msg)
    {
        msg = std::make_shared<test_case_finished>();
        msg->from_json(json);
    }
}
