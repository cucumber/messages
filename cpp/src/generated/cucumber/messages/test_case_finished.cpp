
#include "cucumber/messages/test_case_finished.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
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
        cucumber::messages::to_json(json, camelize("test_case_started_id"), test_case_started_id);
        cucumber::messages::to_json(json, camelize("timestamp"), timestamp);
        cucumber::messages::to_json(json, camelize("will_be_retried"), will_be_retried);
    }

    void test_case_finished::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("test_case_started_id"), test_case_started_id);
        cucumber::messages::from_json(json, camelize("timestamp"), timestamp);
        cucumber::messages::from_json(json, camelize("will_be_retried"), will_be_retried);
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
}
