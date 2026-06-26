#ifndef CUCUMBER_MESSAGES_DURATION_HPP
#define CUCUMBER_MESSAGES_DURATION_HPP

#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the Duration message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // The structure is pretty close of the Timestamp one. For clarity, a second type
    // of message is used.
    //
    // Generated code

    struct duration
    {
        using shared_ptr = duration;//std::shared_ptr<duration>;

        std::size_t seconds;
        std::size_t nanos;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const duration& msg);

    void to_json(nlohmann::json& json, const duration& msg);
    void from_json(const nlohmann::json& json, duration& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<duration>& msg);

}

#endif
