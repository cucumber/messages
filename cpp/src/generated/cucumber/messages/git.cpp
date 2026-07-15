
#include "cucumber/messages/git.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string git::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "remote=", remote);
        cucumber::messages::to_string(oss, ", revision=", revision);
        cucumber::messages::to_string(oss, ", branch=", branch);
        cucumber::messages::to_string(oss, ", tag=", tag);

        return oss.str();
    }

    void git::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("remote"), remote);
        cucumber::messages::to_json(json, camelize("revision"), revision);
        cucumber::messages::to_json(json, camelize("branch"), branch);
        cucumber::messages::to_json(json, camelize("tag"), tag);
    }

    void git::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("remote"), remote);
        cucumber::messages::from_json(json, camelize("revision"), revision);
        cucumber::messages::from_json(json, camelize("branch"), branch);
        cucumber::messages::from_json(json, camelize("tag"), tag);
    }

    std::string git::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const git& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const git& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, git& msg)
    {
        msg.from_json(json);
    }
}
