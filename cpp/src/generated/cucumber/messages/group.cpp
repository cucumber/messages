
#include "cucumber/messages/group.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string group::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "children=", children);
        cucumber::messages::to_string(oss, ", start=", start);
        cucumber::messages::to_string(oss, ", value=", value);

        return oss.str();
    }

    void group::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("children"), children);
        cucumber::messages::to_json(json, camelize("start"), start);
        cucumber::messages::to_json(json, camelize("value"), value);
    }

    void group::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("children"), children);
        cucumber::messages::from_json(json, camelize("start"), start);
        cucumber::messages::from_json(json, camelize("value"), value);
    }

    std::string group::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const group& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const group& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, group& msg)
    {
        msg.from_json(json);
    }
}
