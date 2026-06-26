
#include "cucumber/messages/exception.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string exception::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "type=", type);
        cucumber::messages::to_string(oss, ", message=", message);
        cucumber::messages::to_string(oss, ", stack_trace=", stack_trace);

        return oss.str();
    }

    void exception::to_json(nlohmann::json& json) const
    {
        json[camelize("type")] = type;
        if (message.has_value())
        {
            json[camelize("message")] = message;
        }
        if (stack_trace.has_value())
        {
            json[camelize("stack_trace")] = stack_trace;
        }
    }

    void exception::from_json(const nlohmann::json& json)
    {
        json.at(camelize("type")).get_to(type);
        if (message.has_value())
        {
            json.at(camelize("message")).get_to(message.emplace());
        }
        if (stack_trace.has_value())
        {
            json.at(camelize("stack_trace")).get_to(stack_trace.emplace());
        }
    }

    std::string exception::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const exception& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const exception& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, exception& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<exception>& msg)
    {
        msg = std::make_shared<exception>();
        msg->from_json(json);
    }
}
