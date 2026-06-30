
#include "cucumber/messages/pickle_step.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string pickle_step::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "argument=", argument);
        cucumber::messages::to_string(oss, ", ast_node_ids=", ast_node_ids);
        cucumber::messages::to_string(oss, ", id=", id);
        cucumber::messages::to_string(oss, ", type=", type);
        cucumber::messages::to_string(oss, ", text=", text);

        return oss.str();
    }

    void pickle_step::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("argument"), argument);
        cucumber::messages::to_json(json, camelize("ast_node_ids"), ast_node_ids);
        cucumber::messages::to_json(json, camelize("id"), id);
        cucumber::messages::to_json(json, camelize("type"), type);
        cucumber::messages::to_json(json, camelize("text"), text);
    }

    void pickle_step::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("argument"), argument);
        cucumber::messages::from_json(json, camelize("ast_node_ids"), ast_node_ids);
        cucumber::messages::from_json(json, camelize("id"), id);
        cucumber::messages::from_json(json, camelize("type"), type);
        cucumber::messages::from_json(json, camelize("text"), text);
    }

    std::string pickle_step::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const pickle_step& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const pickle_step& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, pickle_step& msg)
    {
        msg.from_json(json);
    }
}
