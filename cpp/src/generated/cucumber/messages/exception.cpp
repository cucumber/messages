
#include "cucumber/messages/exception.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
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
        cucumber::messages::to_json(json, camelize("type"), type);
        cucumber::messages::to_json(json, camelize("message"), message);
        cucumber::messages::to_json(json, camelize("stack_trace"), stack_trace);
    }

    void exception::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("type"), type);
        cucumber::messages::from_json(json, camelize("message"), message);
        cucumber::messages::from_json(json, camelize("stack_trace"), stack_trace);
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
}
