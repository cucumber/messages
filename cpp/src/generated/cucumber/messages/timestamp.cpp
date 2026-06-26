
#include "cucumber/messages/timestamp.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string timestamp::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "seconds=", seconds);
        cucumber::messages::to_string(oss, ", nanos=", nanos);

        return oss.str();
    }

    void timestamp::to_json(nlohmann::json& json) const
    {
        json[camelize("seconds")] = seconds;
        json[camelize("nanos")] = nanos;
    }

    void timestamp::from_json(const nlohmann::json& json)
    {
        json.at(camelize("seconds")).get_to(seconds);
        json.at(camelize("nanos")).get_to(nanos);
    }

    std::string timestamp::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const timestamp& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const timestamp& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, timestamp& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<timestamp>& msg)
    {
        msg = std::make_shared<timestamp>();
        msg->from_json(json);
    }
}
