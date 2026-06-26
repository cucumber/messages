
#include "cucumber/messages/ci.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string ci::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "name=", name);
        cucumber::messages::to_string(oss, ", url=", url);
        cucumber::messages::to_string(oss, ", build_number=", build_number);
        cucumber::messages::to_string(oss, ", git=", git);

        return oss.str();
    }

    void ci::to_json(nlohmann::json& json) const
    {
        json[camelize("name")] = name;
        if (url.has_value())
        {
            json[camelize("url")] = url;
        }
        if (build_number.has_value())
        {
            json[camelize("build_number")] = build_number;
        }
        if (git.has_value())
        {
            json[camelize("git")] = git;
        }
    }

    void ci::from_json(const nlohmann::json& json)
    {
        json.at(camelize("name")).get_to(name);
        if (url.has_value())
        {
            json.at(camelize("url")).get_to(url.emplace());
        }
        if (build_number.has_value())
        {
            json.at(camelize("build_number")).get_to(build_number.emplace());
        }
        if (git.has_value())
        {
            json.at(camelize("git")).get_to(git.emplace());
        }
    }

    std::string ci::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const ci& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const ci& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, ci& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<ci>& msg)
    {
        msg = std::make_shared<ci>();
        msg->from_json(json);
    }
}
