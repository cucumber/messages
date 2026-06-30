
#include "cucumber/messages/external_attachment.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string external_attachment::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "url=", url);
        cucumber::messages::to_string(oss, ", media_type=", media_type);
        cucumber::messages::to_string(oss, ", test_case_started_id=", test_case_started_id);
        cucumber::messages::to_string(oss, ", test_step_id=", test_step_id);
        cucumber::messages::to_string(oss, ", test_run_hook_started_id=", test_run_hook_started_id);
        cucumber::messages::to_string(oss, ", timestamp=", timestamp);

        return oss.str();
    }

    void external_attachment::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("url"), url);
        cucumber::messages::to_json(json, camelize("media_type"), media_type);
        cucumber::messages::to_json(json, camelize("test_case_started_id"), test_case_started_id);
        cucumber::messages::to_json(json, camelize("test_step_id"), test_step_id);
        cucumber::messages::to_json(json, camelize("test_run_hook_started_id"), test_run_hook_started_id);
        cucumber::messages::to_json(json, camelize("timestamp"), timestamp);
    }

    void external_attachment::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("url"), url);
        cucumber::messages::from_json(json, camelize("media_type"), media_type);
        cucumber::messages::from_json(json, camelize("test_case_started_id"), test_case_started_id);
        cucumber::messages::from_json(json, camelize("test_step_id"), test_step_id);
        cucumber::messages::from_json(json, camelize("test_run_hook_started_id"), test_run_hook_started_id);
        cucumber::messages::from_json(json, camelize("timestamp"), timestamp);
    }

    std::string external_attachment::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const external_attachment& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const external_attachment& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, external_attachment& msg)
    {
        msg.from_json(json);
    }
}
