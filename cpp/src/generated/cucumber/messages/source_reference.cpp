
#include "cucumber/messages/source_reference.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string source_reference::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "uri=", uri);
        cucumber::messages::to_string(oss, ", java_method=", java_method);
        cucumber::messages::to_string(oss, ", java_stack_trace_element=", java_stack_trace_element);
        cucumber::messages::to_string(oss, ", location=", location);

        return oss.str();
    }

    void source_reference::to_json(nlohmann::json& json) const
    {
        if (uri.has_value())
        {
            json[camelize("uri")] = uri;
        }
        if (java_method.has_value())
        {
            json[camelize("java_method")] = java_method;
        }
        if (java_stack_trace_element.has_value())
        {
            json[camelize("java_stack_trace_element")] = java_stack_trace_element;
        }
        if (location.has_value())
        {
            json[camelize("location")] = location;
        }
    }

    void source_reference::from_json(const nlohmann::json& json)
    {
        if (uri.has_value())
        {
            json.at(camelize("uri")).get_to(uri.emplace());
        }
        if (java_method.has_value())
        {
            json.at(camelize("java_method")).get_to(java_method.emplace());
        }
        if (java_stack_trace_element.has_value())
        {
            json.at(camelize("java_stack_trace_element")).get_to(java_stack_trace_element.emplace());
        }
        if (location.has_value())
        {
            json.at(camelize("location")).get_to(location.emplace());
        }
    }

    std::string source_reference::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const source_reference& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const source_reference& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, source_reference& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<source_reference>& msg)
    {
        msg = std::make_shared<source_reference>();
        msg->from_json(json);
    }
}
