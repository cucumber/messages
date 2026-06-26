
#include "cucumber/messages/pickle_doc_string.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string pickle_doc_string::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "media_type=", media_type);
        cucumber::messages::to_string(oss, ", content=", content);

        return oss.str();
    }

    void pickle_doc_string::to_json(nlohmann::json& json) const
    {
        if (media_type.has_value())
        {
            json[camelize("media_type")] = media_type;
        }
        json[camelize("content")] = content;
    }

    void pickle_doc_string::from_json(const nlohmann::json& json)
    {
        if (media_type.has_value())
        {
            json.at(camelize("media_type")).get_to(media_type.emplace());
        }
        json.at(camelize("content")).get_to(content);
    }

    std::string pickle_doc_string::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const pickle_doc_string& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const pickle_doc_string& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, pickle_doc_string& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<pickle_doc_string>& msg)
    {
        msg = std::make_shared<pickle_doc_string>();
        msg->from_json(json);
    }
}
