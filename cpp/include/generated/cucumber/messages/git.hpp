#ifndef CUCUMBER_MESSAGES_GIT_HPP
#define CUCUMBER_MESSAGES_GIT_HPP

#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the Git message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Information about Git, provided by the Build/CI server as environment
    // variables.
    //
    // Generated code

    struct git
    {
        using shared_ptr = git;//std::shared_ptr<git>;

        std::string remote;
        std::string revision;
        std::optional<std::string> branch;
        std::optional<std::string> tag;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const git& msg);

    void to_json(nlohmann::json& json, const git& msg);
    void from_json(const nlohmann::json& json, git& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<git>& msg);

}

#endif
