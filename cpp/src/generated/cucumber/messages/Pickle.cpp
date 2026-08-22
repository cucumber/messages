#include "cucumber/messages/Pickle.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string Pickle::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "id=", id);
        cucumber::messages::to_string(oss, ", uri=", uri);
        cucumber::messages::to_string(oss, ", location=", location);
        cucumber::messages::to_string(oss, ", name=", name);
        cucumber::messages::to_string(oss, ", language=", language);
        cucumber::messages::to_string(oss, ", steps=", steps);
        cucumber::messages::to_string(oss, ", tags=", tags);
        cucumber::messages::to_string(oss, ", astNodeIds=", astNodeIds);

        return oss.str();
    }

    void Pickle::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "id", id);
        cucumber::messages::to_json(json, "uri", uri);
        cucumber::messages::to_json(json, "location", location);
        cucumber::messages::to_json(json, "name", name);
        cucumber::messages::to_json(json, "language", language);
        cucumber::messages::to_json(json, "steps", steps);
        cucumber::messages::to_json(json, "tags", tags);
        cucumber::messages::to_json(json, "astNodeIds", astNodeIds);
    }

    void Pickle::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "id", id);
        cucumber::messages::from_json(json, "uri", uri);
        cucumber::messages::from_json(json, "location", location);
        cucumber::messages::from_json(json, "name", name);
        cucumber::messages::from_json(json, "language", language);
        cucumber::messages::from_json(json, "steps", steps);
        cucumber::messages::from_json(json, "tags", tags);
        cucumber::messages::from_json(json, "astNodeIds", astNodeIds);
    }

    std::string Pickle::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const Pickle& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const Pickle& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, Pickle& msg)
    {
        msg.from_json(json);
    }
}
