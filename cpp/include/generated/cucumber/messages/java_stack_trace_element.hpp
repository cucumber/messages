#ifndef CUCUMBER_MESSAGES_JAVA_STACK_TRACE_ELEMENT_HPP
#define CUCUMBER_MESSAGES_JAVA_STACK_TRACE_ELEMENT_HPP

#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the JavaStackTraceElement message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct java_stack_trace_element
    {
        using shared_ptr = java_stack_trace_element;//std::shared_ptr<java_stack_trace_element>;

        std::string class_name;
        std::string file_name;
        std::string method_name;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const java_stack_trace_element& msg);

    void to_json(nlohmann::json& json, const java_stack_trace_element& msg);
    void from_json(const nlohmann::json& json, java_stack_trace_element& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<java_stack_trace_element>& msg);

}

#endif
