#ifndef CUCUMBER_MESSAGES_EXCEPTION_HPP
#define CUCUMBER_MESSAGES_EXCEPTION_HPP

#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the Exception message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A simplified representation of an exception
    //
    // Generated code

    struct exception
    {
        using shared_ptr = exception;//std::shared_ptr<exception>;

        std::string type;
        std::optional<std::string> message;
        std::optional<std::string> stack_trace;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const exception& msg);

    void to_json(nlohmann::json& json, const exception& msg);
    void from_json(const nlohmann::json& json, exception& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<exception>& msg);

}

#endif
