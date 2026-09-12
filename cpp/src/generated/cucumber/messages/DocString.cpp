#include "cucumber/messages/DocString.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string DocString::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", mediaType=", mediaType);
        cucumber::messages::to_string(oss, ", content=", content);
        cucumber::messages::to_string(oss, ", delimiter=", delimiter);

        return oss.str();
    }

    void DocString::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "location", location);
        cucumber::messages::to_json(json, "mediaType", mediaType);
        cucumber::messages::to_json(json, "content", content);
        cucumber::messages::to_json(json, "delimiter", delimiter);
    }

    void DocString::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "location", location);
        cucumber::messages::from_json(json, "mediaType", mediaType);
        cucumber::messages::from_json(json, "content", content);
        cucumber::messages::from_json(json, "delimiter", delimiter);
    }

    std::string DocString::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const DocString& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const DocString& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, DocString& msg)
    {
        msg.from_json(json);
    }
}
