
#include "cucumber/messages/step_definition.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string step_definition::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "id=", id);
        cucumber::messages::to_string(oss, ", pattern=", pattern);
        cucumber::messages::to_string(oss, ", source_reference=", source_reference);

        return oss.str();
    }

    void step_definition::to_json(nlohmann::json& json) const
    {
        json[camelize("id")] = id;
        json[camelize("pattern")] = pattern;
        json[camelize("source_reference")] = source_reference;
    }

    void step_definition::from_json(const nlohmann::json& json)
    {
        json.at(camelize("id")).get_to(id);
        json.at(camelize("pattern")).get_to(pattern);
        json.at(camelize("source_reference")).get_to(source_reference);
    }

    std::string step_definition::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const step_definition& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const step_definition& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, step_definition& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<step_definition>& msg)
    {
        msg = std::make_shared<step_definition>();
        msg->from_json(json);
    }
}
