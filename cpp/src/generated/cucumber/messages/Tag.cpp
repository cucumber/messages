#include "cucumber/messages/Tag.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string Tag::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", name=", name);
        cucumber::messages::to_string(oss, ", id=", id);

        return oss.str();
    }

    void Tag::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "location", location);
        cucumber::messages::to_json(json, "name", name);
        cucumber::messages::to_json(json, "id", id);
    }

    void Tag::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "location", location);
        cucumber::messages::from_json(json, "name", name);
        cucumber::messages::from_json(json, "id", id);
    }

    std::string Tag::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const Tag& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const Tag& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, Tag& msg)
    {
        msg.from_json(json);
    }
}
