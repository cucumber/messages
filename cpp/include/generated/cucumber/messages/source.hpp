#ifndef CUCUMBER_MESSAGES_SOURCE_HPP
#define CUCUMBER_MESSAGES_SOURCE_HPP

#include "cucumber/messages/source_media_type.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the Source message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A source file, typically a Gherkin document or Java/Ruby/JavaScript source code
    //
    // Generated code

    struct source
    {
        std::string uri;
        std::string data;
        cucumber::messages::source_media_type media_type;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const source& msg);

    void to_json(nlohmann::json& json, const source& msg);
    void from_json(const nlohmann::json& json, source& msg);
}

#endif
