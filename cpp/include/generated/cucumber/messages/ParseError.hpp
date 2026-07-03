#ifndef CUCUMBER_MESSAGES_PARSEERROR_HPP
#define CUCUMBER_MESSAGES_PARSEERROR_HPP

#include "cucumber/messages/SourceReference.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the ParseError message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct ParseError
    {
        std::shared_ptr<SourceReference> source;
        std::string message;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const ParseError& msg);

    void to_json(nlohmann::json& json, const ParseError& msg);
    void from_json(const nlohmann::json& json, ParseError& msg);
}

#endif
