#ifndef CUCUMBER_MESSAGES_DURATION_HPP
#define CUCUMBER_MESSAGES_DURATION_HPP

#include "nlohmann/json_fwd.hpp"
#include <cstddef>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

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

    struct Duration
    {
        std::size_t seconds;
        std::size_t nanos;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Duration& msg);

    void to_json(nlohmann::json& json, const Duration& msg);
    void from_json(const nlohmann::json& json, Duration& msg);
}

#endif
