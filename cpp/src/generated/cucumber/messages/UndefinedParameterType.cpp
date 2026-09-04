#include "cucumber/messages/UndefinedParameterType.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string UndefinedParameterType::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "expression=", expression);
        cucumber::messages::to_string(oss, ", name=", name);

        return oss.str();
    }

    void UndefinedParameterType::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "expression", expression);
        cucumber::messages::to_json(json, "name", name);
    }

    void UndefinedParameterType::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "expression", expression);
        cucumber::messages::from_json(json, "name", name);
    }

    std::string UndefinedParameterType::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const UndefinedParameterType& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const UndefinedParameterType& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, UndefinedParameterType& msg)
    {
        msg.from_json(json);
    }
}

