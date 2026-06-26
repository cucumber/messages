
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
        json[camelize("url")] = url;
        json[camelize("media_type")] = media_type;
        if (test_case_started_id.has_value())
        {
            json[camelize("test_case_started_id")] = test_case_started_id;
        }
        if (test_step_id.has_value())
        {
            json[camelize("test_step_id")] = test_step_id;
        }
        if (test_run_hook_started_id.has_value())
        {
            json[camelize("test_run_hook_started_id")] = test_run_hook_started_id;
        }
        if (timestamp.has_value())
        {
            json[camelize("timestamp")] = timestamp;
        }
    }

    void external_attachment::from_json(const nlohmann::json& json)
    {
        json.at(camelize("url")).get_to(url);
        json.at(camelize("media_type")).get_to(media_type);
        if (test_case_started_id.has_value())
        {
            json.at(camelize("test_case_started_id")).get_to(test_case_started_id.emplace());
        }
        if (test_step_id.has_value())
        {
            json.at(camelize("test_step_id")).get_to(test_step_id.emplace());
        }
        if (test_run_hook_started_id.has_value())
        {
            json.at(camelize("test_run_hook_started_id")).get_to(test_run_hook_started_id.emplace());
        }
        if (timestamp.has_value())
        {
            json.at(camelize("timestamp")).get_to(timestamp.emplace());
        }
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

    void from_json(const nlohmann::json& json, std::shared_ptr<external_attachment>& msg)
    {
        msg = std::make_shared<external_attachment>();
        msg->from_json(json);
    }
}
