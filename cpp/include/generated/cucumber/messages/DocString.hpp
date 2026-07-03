#ifndef CUCUMBER_MESSAGES_DOCSTRING_HPP
#define CUCUMBER_MESSAGES_DOCSTRING_HPP

#include "cucumber/messages/Location.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the DocString message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct DocString
    {
        std::shared_ptr<Location> location;
        std::optional<std::string> mediaType;
        std::string content;
        std::string delimiter;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const DocString& msg);

    void to_json(nlohmann::json& json, const DocString& msg);
    void from_json(const nlohmann::json& json, DocString& msg);
}

#endif
