#ifndef CUCUMBER_MESSAGES_JAVA_METHOD_HPP
#define CUCUMBER_MESSAGES_JAVA_METHOD_HPP

#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <string>
#include <vector>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the JavaMethod message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct JavaMethod
    {
        std::string className;
        std::string methodName;
        std::vector<std::string> methodParameterTypes;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const JavaMethod& msg);

    void to_json(nlohmann::json& json, const JavaMethod& msg);
    void from_json(const nlohmann::json& json, JavaMethod& msg);
}

#endif
