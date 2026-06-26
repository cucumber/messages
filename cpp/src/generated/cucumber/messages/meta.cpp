
#include "cucumber/messages/meta.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string meta::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "protocol_version=", protocol_version);
        cucumber::messages::to_string(oss, ", implementation=", implementation);
        cucumber::messages::to_string(oss, ", runtime=", runtime);
        cucumber::messages::to_string(oss, ", os=", os);
        cucumber::messages::to_string(oss, ", cpu=", cpu);
        cucumber::messages::to_string(oss, ", ci=", ci);

        return oss.str();
    }

    void meta::to_json(nlohmann::json& json) const
    {
        json[camelize("protocol_version")] = protocol_version;
        json[camelize("implementation")] = implementation;
        json[camelize("runtime")] = runtime;
        json[camelize("os")] = os;
        json[camelize("cpu")] = cpu;
        if (ci.has_value())
        {
            json[camelize("ci")] = ci;
        }
    }

    void meta::from_json(const nlohmann::json& json)
    {
        json.at(camelize("protocol_version")).get_to(protocol_version);
        json.at(camelize("implementation")).get_to(implementation);
        json.at(camelize("runtime")).get_to(runtime);
        json.at(camelize("os")).get_to(os);
        json.at(camelize("cpu")).get_to(cpu);
        if (ci.has_value())
        {
            json.at(camelize("ci")).get_to(ci.emplace());
        }
    }

    std::string meta::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const meta& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const meta& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, meta& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<meta>& msg)
    {
        msg = std::make_shared<meta>();
        msg->from_json(json);
    }
}
