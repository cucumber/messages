#include "cucumber/messages/PickleDocString.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string PickleDocString::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "argumentIndex=", argumentIndex);
        cucumber::messages::to_string(oss, ", mediaType=", mediaType);
        cucumber::messages::to_string(oss, ", content=", content);

        return oss.str();
    }

    void PickleDocString::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "argumentIndex", argumentIndex);
        cucumber::messages::to_json(json, "mediaType", mediaType);
        cucumber::messages::to_json(json, "content", content);
    }

    void PickleDocString::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "argumentIndex", argumentIndex);
        cucumber::messages::from_json(json, "mediaType", mediaType);
        cucumber::messages::from_json(json, "content", content);
    }

    std::string PickleDocString::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const PickleDocString& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const PickleDocString& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, PickleDocString& msg)
    {
        msg.from_json(json);
    }
}
