#include "cucumber/messages/Source.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string Source::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "uri=", uri);
        cucumber::messages::to_string(oss, ", data=", data);
        cucumber::messages::to_string(oss, ", mediaType=", mediaType);

        return oss.str();
    }

    void Source::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "uri", uri);
        cucumber::messages::to_json(json, "data", data);
        cucumber::messages::to_json(json, "mediaType", mediaType);
    }

    void Source::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "uri", uri);
        cucumber::messages::from_json(json, "data", data);
        cucumber::messages::from_json(json, "mediaType", mediaType);
    }

    std::string Source::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const Source& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const Source& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, Source& msg)
    {
        msg.from_json(json);
    }
}
