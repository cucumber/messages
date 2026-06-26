
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
        if (argument.has_value())
        {
            json[camelize("argument")] = argument;
        }
        json[camelize("ast_node_ids")] = ast_node_ids;
        json[camelize("id")] = id;
        if (type.has_value())
        {
            json[camelize("type")] = type;
        }
        json[camelize("text")] = text;
    }

    void pickle_step::from_json(const nlohmann::json& json)
    {
        if (argument.has_value())
        {
            json.at(camelize("argument")).get_to(argument.emplace());
        }
        json.at(camelize("ast_node_ids")).get_to(ast_node_ids);
        json.at(camelize("id")).get_to(id);
        if (type.has_value())
        {
            json.at(camelize("type")).get_to(type.emplace());
        }
        json.at(camelize("text")).get_to(text);
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

    void from_json(const nlohmann::json& json, std::shared_ptr<pickle_step>& msg)
    {
        msg = std::make_shared<pickle_step>();
        msg->from_json(json);
    }
}
