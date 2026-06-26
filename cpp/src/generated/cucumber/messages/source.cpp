
#include "cucumber/messages/source.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string source::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "uri=", uri);
        cucumber::messages::to_string(oss, ", data=", data);
        cucumber::messages::to_string(oss, ", media_type=", media_type);

        return oss.str();
    }

    void source::to_json(nlohmann::json& json) const
    {
        json[camelize("uri")] = uri;
        json[camelize("data")] = data;
        json[camelize("media_type")] = media_type;
    }

    void source::from_json(const nlohmann::json& json)
    {
        json.at(camelize("uri")).get_to(uri);
        json.at(camelize("data")).get_to(data);
        json.at(camelize("media_type")).get_to(media_type);
    }

    std::string source::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const source& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const source& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, source& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<source>& msg)
    {
        msg = std::make_shared<source>();
        msg->from_json(json);
    }
}
