
#include "cucumber/messages/rule_child.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string rule_child::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "background=", background);
        cucumber::messages::to_string(oss, ", scenario=", scenario);

        return oss.str();
    }

    void rule_child::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("background"), background);
        cucumber::messages::to_json(json, camelize("scenario"), scenario);
    }

    void rule_child::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("background"), background);
        cucumber::messages::from_json(json, camelize("scenario"), scenario);
    }

    std::string rule_child::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const rule_child& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const rule_child& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, rule_child& msg)
    {
        msg.from_json(json);
    }
}
