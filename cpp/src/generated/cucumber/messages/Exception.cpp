#include "cucumber/messages/Exception.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string Exception::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "type=", type);
        cucumber::messages::to_string(oss, ", message=", message);
        cucumber::messages::to_string(oss, ", stackTrace=", stackTrace);

        return oss.str();
    }

    void Exception::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "type", type);
        cucumber::messages::to_json(json, "message", message);
        cucumber::messages::to_json(json, "stackTrace", stackTrace);
    }

    void Exception::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "type", type);
        cucumber::messages::from_json(json, "message", message);
        cucumber::messages::from_json(json, "stackTrace", stackTrace);
    }

    std::string Exception::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const Exception& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const Exception& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, Exception& msg)
    {
        msg.from_json(json);
    }
}
