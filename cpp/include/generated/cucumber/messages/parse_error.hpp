#ifndef CUCUMBER_MESSAGES_PARSE_ERROR_HPP
#define CUCUMBER_MESSAGES_PARSE_ERROR_HPP

#include "cucumber/messages/source_reference.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the ParseError message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct parse_error
    {
        using shared_ptr = parse_error;//std::shared_ptr<parse_error>;

        cucumber::messages::source_reference::shared_ptr source;
        std::string message;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const parse_error& msg);

    void to_json(nlohmann::json& json, const parse_error& msg);
    void from_json(const nlohmann::json& json, parse_error& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<parse_error>& msg);

}

#endif
