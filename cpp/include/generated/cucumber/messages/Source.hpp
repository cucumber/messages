#ifndef CUCUMBER_MESSAGES_SOURCE_HPP
#define CUCUMBER_MESSAGES_SOURCE_HPP

#include "cucumber/messages/SourceMediaType.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Source message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A source file, typically a Gherkin document or Java/Ruby/JavaScript source code
    //
    // Generated code

    struct Source
    {
        std::string uri;
        std::string data;
        SourceMediaType mediaType;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Source& msg);

    void to_json(nlohmann::json& json, const Source& msg);
    void from_json(const nlohmann::json& json, Source& msg);
}

#endif
