
#include "cucumber/messages/test_case_started.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string test_case_started::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "attempt=", attempt);
        cucumber::messages::to_string(oss, ", id=", id);
        cucumber::messages::to_string(oss, ", test_case_id=", test_case_id);
        cucumber::messages::to_string(oss, ", worker_id=", worker_id);
        cucumber::messages::to_string(oss, ", timestamp=", timestamp);

        return oss.str();
    }

    void test_case_started::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("attempt"), attempt);
        cucumber::messages::to_json(json, camelize("id"), id);
        cucumber::messages::to_json(json, camelize("test_case_id"), test_case_id);
        cucumber::messages::to_json(json, camelize("worker_id"), worker_id);
        cucumber::messages::to_json(json, camelize("timestamp"), timestamp);
    }

    void test_case_started::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("attempt"), attempt);
        cucumber::messages::from_json(json, camelize("id"), id);
        cucumber::messages::from_json(json, camelize("test_case_id"), test_case_id);
        cucumber::messages::from_json(json, camelize("worker_id"), worker_id);
        cucumber::messages::from_json(json, camelize("timestamp"), timestamp);
    }

    std::string test_case_started::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const test_case_started& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const test_case_started& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, test_case_started& msg)
    {
        msg.from_json(json);
    }
}
