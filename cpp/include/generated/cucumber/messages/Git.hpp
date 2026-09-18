#ifndef CUCUMBER_MESSAGES_GIT_HPP
#define CUCUMBER_MESSAGES_GIT_HPP

#include "nlohmann/json_fwd.hpp"
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Git message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Information about Git, provided by the Build/CI server as environment
    // variables.
    //

    struct Git
    {
        std::string remote;
        std::string revision;
        std::optional<std::string> branch;
        std::optional<std::string> tag;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Git& msg);

    void to_json(nlohmann::json& json, const Git& msg);
    void from_json(const nlohmann::json& json, Git& msg);
}

#endif
