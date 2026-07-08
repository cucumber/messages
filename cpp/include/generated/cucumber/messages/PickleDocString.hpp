#ifndef CUCUMBER_MESSAGES_PICKLE_DOC_STRING_HPP
#define CUCUMBER_MESSAGES_PICKLE_DOC_STRING_HPP

#include "nlohmann/json_fwd.hpp"
#include <cstddef>
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the PickleDocString message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct PickleDocString
    {
        std::optional<std::size_t> argumentIndex;
        std::optional<std::string> mediaType;
        std::string content;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const PickleDocString& msg);

    void to_json(nlohmann::json& json, const PickleDocString& msg);
    void from_json(const nlohmann::json& json, PickleDocString& msg);
}

#endif
