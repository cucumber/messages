
#include "cucumber/messages/step_definition_pattern.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string step_definition_pattern::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "source=", source);
        cucumber::messages::to_string(oss, ", type=", type);

        return oss.str();
    }

    void step_definition_pattern::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("source"), source);
        cucumber::messages::to_json(json, camelize("type"), type);
    }

    void step_definition_pattern::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("source"), source);
        cucumber::messages::from_json(json, camelize("type"), type);
    }

    std::string step_definition_pattern::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const step_definition_pattern& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const step_definition_pattern& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, step_definition_pattern& msg)
    {
        msg.from_json(json);
    }
}
