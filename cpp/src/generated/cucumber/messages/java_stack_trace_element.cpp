
#include "cucumber/messages/java_stack_trace_element.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string java_stack_trace_element::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "class_name=", class_name);
        cucumber::messages::to_string(oss, ", file_name=", file_name);
        cucumber::messages::to_string(oss, ", method_name=", method_name);

        return oss.str();
    }

    void java_stack_trace_element::to_json(nlohmann::json& json) const
    {
        json[camelize("class_name")] = class_name;
        json[camelize("file_name")] = file_name;
        json[camelize("method_name")] = method_name;
    }

    void java_stack_trace_element::from_json(const nlohmann::json& json)
    {
        json.at(camelize("class_name")).get_to(class_name);
        json.at(camelize("file_name")).get_to(file_name);
        json.at(camelize("method_name")).get_to(method_name);
    }

    std::string java_stack_trace_element::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const java_stack_trace_element& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const java_stack_trace_element& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, java_stack_trace_element& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<java_stack_trace_element>& msg)
    {
        msg = std::make_shared<java_stack_trace_element>();
        msg->from_json(json);
    }
}
