#include "cucumber/messages/Duration.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string Duration::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "seconds=", seconds);
        cucumber::messages::to_string(oss, ", nanos=", nanos);

        return oss.str();
    }

    void Duration::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "seconds", seconds);
        cucumber::messages::to_json(json, "nanos", nanos);
    }

    void Duration::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "seconds", seconds);
        cucumber::messages::from_json(json, "nanos", nanos);
    }

    std::string Duration::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const Duration& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const Duration& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, Duration& msg)
    {
        msg.from_json(json);
    }
}
