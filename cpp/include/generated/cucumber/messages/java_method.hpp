#ifndef CUCUMBER_MESSAGES_JAVA_METHOD_HPP
#define CUCUMBER_MESSAGES_JAVA_METHOD_HPP

#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

namespace cucumber::messages
{
    //
    // Represents the JavaMethod message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct java_method
    {
        std::string class_name;
        std::string method_name;
        std::vector<std::string> method_parameter_types;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const java_method& msg);

    void to_json(nlohmann::json& json, const java_method& msg);
    void from_json(const nlohmann::json& json, java_method& msg);
}

#endif
