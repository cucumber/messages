
#include "cucumber/messages/parse_error.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string parse_error::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "source=", source);
        cucumber::messages::to_string(oss, ", message=", message);

        return oss.str();
    }

    void parse_error::to_json(nlohmann::json& json) const
    {
        json[camelize("source")] = source;
        json[camelize("message")] = message;
    }

    void parse_error::from_json(const nlohmann::json& json)
    {
        json.at(camelize("source")).get_to(source);
        json.at(camelize("message")).get_to(message);
    }

    std::string parse_error::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const parse_error& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const parse_error& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, parse_error& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<parse_error>& msg)
    {
        msg = std::make_shared<parse_error>();
        msg->from_json(json);
    }
}
