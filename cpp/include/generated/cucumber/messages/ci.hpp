#ifndef CUCUMBER_MESSAGES_CI_HPP
#define CUCUMBER_MESSAGES_CI_HPP

#include "cucumber/messages/git.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the Ci message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // CI environment
    //
    // Generated code

    struct ci
    {
        std::string name;
        std::optional<std::string> url;
        std::optional<std::string> build_number;
        std::optional<cucumber::messages::git> git;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const ci& msg);

    void to_json(nlohmann::json& json, const ci& msg);
    void from_json(const nlohmann::json& json, ci& msg);
}

#endif
