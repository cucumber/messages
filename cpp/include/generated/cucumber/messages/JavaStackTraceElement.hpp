#ifndef CUCUMBER_MESSAGES_JAVA_STACK_TRACE_ELEMENT_HPP
#define CUCUMBER_MESSAGES_JAVA_STACK_TRACE_ELEMENT_HPP

#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the JavaStackTraceElement message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct JavaStackTraceElement
    {
        std::string className;
        std::string fileName;
        std::string methodName;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const JavaStackTraceElement& msg);

    void to_json(nlohmann::json& json, const JavaStackTraceElement& msg);
    void from_json(const nlohmann::json& json, JavaStackTraceElement& msg);
}

#endif
