#include "cucumber/messages/JavaMethod.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string JavaMethod::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "className=", className);
        cucumber::messages::to_string(oss, ", methodName=", methodName);
        cucumber::messages::to_string(oss, ", methodParameterTypes=", methodParameterTypes);

        return oss.str();
    }

    void JavaMethod::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "className", className);
        cucumber::messages::to_json(json, "methodName", methodName);
        cucumber::messages::to_json(json, "methodParameterTypes", methodParameterTypes);
    }

    void JavaMethod::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "className", className);
        cucumber::messages::from_json(json, "methodName", methodName);
        cucumber::messages::from_json(json, "methodParameterTypes", methodParameterTypes);
    }

    std::string JavaMethod::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const JavaMethod& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const JavaMethod& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, JavaMethod& msg)
    {
        msg.from_json(json);
    }
}
