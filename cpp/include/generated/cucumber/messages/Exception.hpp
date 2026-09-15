#ifndef CUCUMBER_MESSAGES_EXCEPTION_HPP
#define CUCUMBER_MESSAGES_EXCEPTION_HPP

#include "nlohmann/json_fwd.hpp"
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Exception message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A simplified representation of an exception
    //

    struct Exception
    {
        std::string type;
        std::optional<std::string> message;
        std::optional<std::string> stackTrace;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Exception& msg);

    void to_json(nlohmann::json& json, const Exception& msg);
    void from_json(const nlohmann::json& json, Exception& msg);
}

#endif
