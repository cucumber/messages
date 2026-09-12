#include "cucumber/messages/ParameterType.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string ParameterType::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "name=", name);
        cucumber::messages::to_string(oss, ", regularExpressions=", regularExpressions);
        cucumber::messages::to_string(oss, ", preferForRegularExpressionMatch=", preferForRegularExpressionMatch);
        cucumber::messages::to_string(oss, ", useForSnippets=", useForSnippets);
        cucumber::messages::to_string(oss, ", id=", id);
        cucumber::messages::to_string(oss, ", sourceReference=", sourceReference);

        return oss.str();
    }

    void ParameterType::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "name", name);
        cucumber::messages::to_json(json, "regularExpressions", regularExpressions);
        cucumber::messages::to_json(json, "preferForRegularExpressionMatch", preferForRegularExpressionMatch);
        cucumber::messages::to_json(json, "useForSnippets", useForSnippets);
        cucumber::messages::to_json(json, "id", id);
        cucumber::messages::to_json(json, "sourceReference", sourceReference);
    }

    void ParameterType::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "name", name);
        cucumber::messages::from_json(json, "regularExpressions", regularExpressions);
        cucumber::messages::from_json(json, "preferForRegularExpressionMatch", preferForRegularExpressionMatch);
        cucumber::messages::from_json(json, "useForSnippets", useForSnippets);
        cucumber::messages::from_json(json, "id", id);
        cucumber::messages::from_json(json, "sourceReference", sourceReference);
    }

    std::string ParameterType::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const ParameterType& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const ParameterType& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, ParameterType& msg)
    {
        msg.from_json(json);
    }
}
