
#include "cucumber/messages/location.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string location::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "line=", line);
        cucumber::messages::to_string(oss, ", column=", column);

        return oss.str();
    }

    void location::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("line"), line);
        cucumber::messages::to_json(json, camelize("column"), column);
    }

    void location::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("line"), line);
        cucumber::messages::from_json(json, camelize("column"), column);
    }

    std::string location::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const location& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const location& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, location& msg)
    {
        msg.from_json(json);
    }
}
