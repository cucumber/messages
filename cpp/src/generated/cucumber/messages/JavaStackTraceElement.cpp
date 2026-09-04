#include "cucumber/messages/JavaStackTraceElement.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string JavaStackTraceElement::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "className=", className);
        cucumber::messages::to_string(oss, ", fileName=", fileName);
        cucumber::messages::to_string(oss, ", methodName=", methodName);

        return oss.str();
    }

    void JavaStackTraceElement::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "className", className);
        cucumber::messages::to_json(json, "fileName", fileName);
        cucumber::messages::to_json(json, "methodName", methodName);
    }

    void JavaStackTraceElement::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "className", className);
        cucumber::messages::from_json(json, "fileName", fileName);
        cucumber::messages::from_json(json, "methodName", methodName);
    }

    std::string JavaStackTraceElement::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const JavaStackTraceElement& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const JavaStackTraceElement& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, JavaStackTraceElement& msg)
    {
        msg.from_json(json);
    }
}
