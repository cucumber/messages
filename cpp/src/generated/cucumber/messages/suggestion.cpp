
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
        json[camelize("id")] = id;
        json[camelize("pickle_step_id")] = pickle_step_id;
        json[camelize("snippets")] = snippets;
    }

    void suggestion::from_json(const nlohmann::json& json)
    {
        json.at(camelize("id")).get_to(id);
        json.at(camelize("pickle_step_id")).get_to(pickle_step_id);
        json.at(camelize("snippets")).get_to(snippets);
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

    void from_json(const nlohmann::json& json, std::shared_ptr<suggestion>& msg)
    {
        msg = std::make_shared<suggestion>();
        msg->from_json(json);
    }
}
