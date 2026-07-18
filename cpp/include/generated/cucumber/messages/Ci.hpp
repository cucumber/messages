#ifndef CUCUMBER_MESSAGES_CI_HPP
#define CUCUMBER_MESSAGES_CI_HPP

#include "cucumber/messages/Git.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Ci message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // CI environment
    //

    struct Ci
    {
        std::string name;
        std::optional<std::string> url;
        std::optional<std::string> buildNumber;
        std::optional<std::shared_ptr<Git>> git;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Ci& msg);

    void to_json(nlohmann::json& json, const Ci& msg);
    void from_json(const nlohmann::json& json, Ci& msg);
}

#endif
