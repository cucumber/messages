#include "cucumber/messages/SourceReference.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string SourceReference::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "uri=", uri);
        cucumber::messages::to_string(oss, ", javaMethod=", javaMethod);
        cucumber::messages::to_string(oss, ", javaStackTraceElement=", javaStackTraceElement);
        cucumber::messages::to_string(oss, ", location=", location);

        return oss.str();
    }

    void SourceReference::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "uri", uri);
        cucumber::messages::to_json(json, "javaMethod", javaMethod);
        cucumber::messages::to_json(json, "javaStackTraceElement", javaStackTraceElement);
        cucumber::messages::to_json(json, "location", location);
    }

    void SourceReference::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "uri", uri);
        cucumber::messages::from_json(json, "javaMethod", javaMethod);
        cucumber::messages::from_json(json, "javaStackTraceElement", javaStackTraceElement);
        cucumber::messages::from_json(json, "location", location);
    }

    std::string SourceReference::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const SourceReference& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const SourceReference& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, SourceReference& msg)
    {
        msg.from_json(json);
    }
}
