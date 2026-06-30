
#include "cucumber/messages/doc_string.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string doc_string::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", media_type=", media_type);
        cucumber::messages::to_string(oss, ", content=", content);
        cucumber::messages::to_string(oss, ", delimiter=", delimiter);

        return oss.str();
    }

    void doc_string::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("location"), location);
        cucumber::messages::to_json(json, camelize("media_type"), media_type);
        cucumber::messages::to_json(json, camelize("content"), content);
        cucumber::messages::to_json(json, camelize("delimiter"), delimiter);
    }

    void doc_string::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("location"), location);
        cucumber::messages::from_json(json, camelize("media_type"), media_type);
        cucumber::messages::from_json(json, camelize("content"), content);
        cucumber::messages::from_json(json, camelize("delimiter"), delimiter);
    }

    std::string doc_string::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const doc_string& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const doc_string& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, doc_string& msg)
    {
        msg.from_json(json);
    }
}
