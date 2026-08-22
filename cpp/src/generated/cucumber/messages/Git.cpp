#include "cucumber/messages/Git.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string Git::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "remote=", remote);
        cucumber::messages::to_string(oss, ", revision=", revision);
        cucumber::messages::to_string(oss, ", branch=", branch);
        cucumber::messages::to_string(oss, ", tag=", tag);

        return oss.str();
    }

    void Git::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "remote", remote);
        cucumber::messages::to_json(json, "revision", revision);
        cucumber::messages::to_json(json, "branch", branch);
        cucumber::messages::to_json(json, "tag", tag);
    }

    void Git::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "remote", remote);
        cucumber::messages::from_json(json, "revision", revision);
        cucumber::messages::from_json(json, "branch", branch);
        cucumber::messages::from_json(json, "tag", tag);
    }

    std::string Git::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const Git& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const Git& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, Git& msg)
    {
        msg.from_json(json);
    }
}
