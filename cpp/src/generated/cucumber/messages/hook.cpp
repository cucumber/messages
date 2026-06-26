
#include "cucumber/messages/hook.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string hook::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "id=", id);
        cucumber::messages::to_string(oss, ", name=", name);
        cucumber::messages::to_string(oss, ", source_reference=", source_reference);
        cucumber::messages::to_string(oss, ", tag_expression=", tag_expression);
        cucumber::messages::to_string(oss, ", type=", type);

        return oss.str();
    }

    void hook::to_json(nlohmann::json& json) const
    {
        json[camelize("id")] = id;
        if (name.has_value())
        {
            json[camelize("name")] = name;
        }
        json[camelize("source_reference")] = source_reference;
        if (tag_expression.has_value())
        {
            json[camelize("tag_expression")] = tag_expression;
        }
        if (type.has_value())
        {
            json[camelize("type")] = type;
        }
    }

    void hook::from_json(const nlohmann::json& json)
    {
        json.at(camelize("id")).get_to(id);
        if (name.has_value())
        {
            json.at(camelize("name")).get_to(name.emplace());
        }
        json.at(camelize("source_reference")).get_to(source_reference);
        if (tag_expression.has_value())
        {
            json.at(camelize("tag_expression")).get_to(tag_expression.emplace());
        }
        if (type.has_value())
        {
            json.at(camelize("type")).get_to(type.emplace());
        }
    }

    std::string hook::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const hook& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const hook& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, hook& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<hook>& msg)
    {
        msg = std::make_shared<hook>();
        msg->from_json(json);
    }
}
