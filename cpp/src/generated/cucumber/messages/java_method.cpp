
#include "cucumber/messages/java_method.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string java_method::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "class_name=", class_name);
        cucumber::messages::to_string(oss, ", method_name=", method_name);
        cucumber::messages::to_string(oss, ", method_parameter_types=", method_parameter_types);

        return oss.str();
    }

    void java_method::to_json(nlohmann::json& json) const
    {
        json[camelize("class_name")] = class_name;
        json[camelize("method_name")] = method_name;
        json[camelize("method_parameter_types")] = method_parameter_types;
    }

    void java_method::from_json(const nlohmann::json& json)
    {
        json.at(camelize("class_name")).get_to(class_name);
        json.at(camelize("method_name")).get_to(method_name);
        json.at(camelize("method_parameter_types")).get_to(method_parameter_types);
    }

    std::string java_method::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const java_method& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const java_method& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, java_method& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<java_method>& msg)
    {
        msg = std::make_shared<java_method>();
        msg->from_json(json);
    }
}
