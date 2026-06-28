
#include "cucumber/messages/step.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string step::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", keyword=", keyword);
        cucumber::messages::to_string(oss, ", keyword_type=", keyword_type);
        cucumber::messages::to_string(oss, ", text=", text);
        cucumber::messages::to_string(oss, ", doc_string=", doc_string);
        cucumber::messages::to_string(oss, ", data_table=", data_table);
        cucumber::messages::to_string(oss, ", id=", id);

        return oss.str();
    }

    void step::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("location"), location);
        cucumber::messages::to_json(json, camelize("keyword"), keyword);
        cucumber::messages::to_json(json, camelize("keyword_type"), keyword_type);
        cucumber::messages::to_json(json, camelize("text"), text);
        cucumber::messages::to_json(json, camelize("doc_string"), doc_string);
        cucumber::messages::to_json(json, camelize("data_table"), data_table);
        cucumber::messages::to_json(json, camelize("id"), id);
    }

    void step::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("location"), location);
        cucumber::messages::from_json(json, camelize("keyword"), keyword);
        cucumber::messages::from_json(json, camelize("keyword_type"), keyword_type);
        cucumber::messages::from_json(json, camelize("text"), text);
        cucumber::messages::from_json(json, camelize("doc_string"), doc_string);
        cucumber::messages::from_json(json, camelize("data_table"), data_table);
        cucumber::messages::from_json(json, camelize("id"), id);
    }

    std::string step::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const step& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const step& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, step& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<step>& msg)
    {
        msg = std::make_shared<step>();
        msg->from_json(json);
    }
}
