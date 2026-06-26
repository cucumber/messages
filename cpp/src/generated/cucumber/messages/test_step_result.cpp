
#include "cucumber/messages/test_step_result.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string test_step_result::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "duration=", duration);
        cucumber::messages::to_string(oss, ", message=", message);
        cucumber::messages::to_string(oss, ", status=", status);
        cucumber::messages::to_string(oss, ", exception=", exception);

        return oss.str();
    }

    void test_step_result::to_json(nlohmann::json& json) const
    {
        json[camelize("duration")] = duration;
        if (message.has_value())
        {
            json[camelize("message")] = message;
        }
        json[camelize("status")] = status;
        if (exception.has_value())
        {
            json[camelize("exception")] = exception;
        }
    }

    void test_step_result::from_json(const nlohmann::json& json)
    {
        json.at(camelize("duration")).get_to(duration);
        if (message.has_value())
        {
            json.at(camelize("message")).get_to(message.emplace());
        }
        json.at(camelize("status")).get_to(status);
        if (exception.has_value())
        {
            json.at(camelize("exception")).get_to(exception.emplace());
        }
    }

    std::string test_step_result::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const test_step_result& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const test_step_result& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, test_step_result& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<test_step_result>& msg)
    {
        msg = std::make_shared<test_step_result>();
        msg->from_json(json);
    }
}
