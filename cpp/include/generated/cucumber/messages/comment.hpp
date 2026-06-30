#ifndef CUCUMBER_MESSAGES_COMMENT_HPP
#define CUCUMBER_MESSAGES_COMMENT_HPP

#include "cucumber/messages/location.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the Comment message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A comment in a Gherkin document
    //
    // Generated code

    struct comment
    {
        cucumber::messages::location location;
        std::string text;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const comment& msg);

    void to_json(nlohmann::json& json, const comment& msg);
    void from_json(const nlohmann::json& json, comment& msg);
}

#endif
