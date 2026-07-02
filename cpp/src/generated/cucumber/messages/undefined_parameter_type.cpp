
#include "cucumber/messages/undefined_parameter_type.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string undefined_parameter_type::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "expression=", expression);
        cucumber::messages::to_string(oss, ", name=", name);

        return oss.str();
    }

    void undefined_parameter_type::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("expression"), expression);
        cucumber::messages::to_json(json, camelize("name"), name);
    }

    void undefined_parameter_type::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("expression"), expression);
        cucumber::messages::from_json(json, camelize("name"), name);
    }

    std::string undefined_parameter_type::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const undefined_parameter_type& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const undefined_parameter_type& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, undefined_parameter_type& msg)
    {
        msg.from_json(json);
    }
}
