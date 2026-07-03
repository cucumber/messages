#ifndef CUCUMBER_MESSAGES_UNDEFINEDPARAMETERTYPE_HPP
#define CUCUMBER_MESSAGES_UNDEFINEDPARAMETERTYPE_HPP

#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the UndefinedParameterType message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct UndefinedParameterType
    {
        std::string expression;
        std::string name;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const UndefinedParameterType& msg);

    void to_json(nlohmann::json& json, const UndefinedParameterType& msg);
    void from_json(const nlohmann::json& json, UndefinedParameterType& msg);
}

#endif
