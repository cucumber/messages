
#include "cucumber/messages/attachment.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string attachment::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "body=", body);
        cucumber::messages::to_string(oss, ", content_encoding=", content_encoding);
        cucumber::messages::to_string(oss, ", file_name=", file_name);
        cucumber::messages::to_string(oss, ", media_type=", media_type);
        cucumber::messages::to_string(oss, ", source=", source);
        cucumber::messages::to_string(oss, ", test_case_started_id=", test_case_started_id);
        cucumber::messages::to_string(oss, ", test_step_id=", test_step_id);
        cucumber::messages::to_string(oss, ", url=", url);
        cucumber::messages::to_string(oss, ", test_run_started_id=", test_run_started_id);
        cucumber::messages::to_string(oss, ", test_run_hook_started_id=", test_run_hook_started_id);
        cucumber::messages::to_string(oss, ", timestamp=", timestamp);

        return oss.str();
    }

    void attachment::to_json(nlohmann::json& json) const
    {
        json[camelize("body")] = body;
        json[camelize("content_encoding")] = content_encoding;
        if (file_name.has_value())
        {
            json[camelize("file_name")] = file_name;
        }
        json[camelize("media_type")] = media_type;
        if (source.has_value())
        {
            json[camelize("source")] = source;
        }
        if (test_case_started_id.has_value())
        {
            json[camelize("test_case_started_id")] = test_case_started_id;
        }
        if (test_step_id.has_value())
        {
            json[camelize("test_step_id")] = test_step_id;
        }
        if (url.has_value())
        {
            json[camelize("url")] = url;
        }
        if (test_run_started_id.has_value())
        {
            json[camelize("test_run_started_id")] = test_run_started_id;
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

    void attachment::from_json(const nlohmann::json& json)
    {
        json.at(camelize("body")).get_to(body);
        json.at(camelize("content_encoding")).get_to(content_encoding);
        if (file_name.has_value())
        {
            json.at(camelize("file_name")).get_to(file_name.emplace());
        }
        json.at(camelize("media_type")).get_to(media_type);
        if (source.has_value())
        {
            json.at(camelize("source")).get_to(source.emplace());
        }
        if (test_case_started_id.has_value())
        {
            json.at(camelize("test_case_started_id")).get_to(test_case_started_id.emplace());
        }
        if (test_step_id.has_value())
        {
            json.at(camelize("test_step_id")).get_to(test_step_id.emplace());
        }
        if (url.has_value())
        {
            json.at(camelize("url")).get_to(url.emplace());
        }
        if (test_run_started_id.has_value())
        {
            json.at(camelize("test_run_started_id")).get_to(test_run_started_id.emplace());
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

    std::string attachment::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const attachment& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const attachment& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, attachment& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<attachment>& msg)
    {
        msg = std::make_shared<attachment>();
        msg->from_json(json);
    }
}
