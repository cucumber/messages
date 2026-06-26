
#include "cucumber/messages/git.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
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
        json[camelize("remote")] = remote;
        json[camelize("revision")] = revision;
        if (branch.has_value())
        {
            json[camelize("branch")] = branch;
        }
        if (tag.has_value())
        {
            json[camelize("tag")] = tag;
        }
    }

    void git::from_json(const nlohmann::json& json)
    {
        json.at(camelize("remote")).get_to(remote);
        json.at(camelize("revision")).get_to(revision);
        if (branch.has_value())
        {
            json.at(camelize("branch")).get_to(branch.emplace());
        }
        if (tag.has_value())
        {
            json.at(camelize("tag")).get_to(tag.emplace());
        }
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

    void from_json(const nlohmann::json& json, std::shared_ptr<git>& msg)
    {
        msg = std::make_shared<git>();
        msg->from_json(json);
    }
}
