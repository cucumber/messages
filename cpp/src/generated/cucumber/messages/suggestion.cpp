
#include "cucumber/messages/suggestion.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string suggestion::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "id=", id);
        cucumber::messages::to_string(oss, ", pickle_step_id=", pickle_step_id);
        cucumber::messages::to_string(oss, ", snippets=", snippets);

        return oss.str();
    }

    void suggestion::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("id"), id);
        cucumber::messages::to_json(json, camelize("pickle_step_id"), pickle_step_id);
        cucumber::messages::to_json(json, camelize("snippets"), snippets);
    }

    void suggestion::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("id"), id);
        cucumber::messages::from_json(json, camelize("pickle_step_id"), pickle_step_id);
        cucumber::messages::from_json(json, camelize("snippets"), snippets);
    }

    std::string suggestion::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const suggestion& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const suggestion& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, suggestion& msg)
    {
        msg.from_json(json);
    }
}
