#ifndef CUCUMBER_MESSAGES_TIMESTAMP_HPP
#define CUCUMBER_MESSAGES_TIMESTAMP_HPP

#include "nlohmann/json_fwd.hpp"
#include <cstddef>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Timestamp message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //

    struct Timestamp
    {
        std::size_t seconds;
        std::size_t nanos;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Timestamp& msg);

    void to_json(nlohmann::json& json, const Timestamp& msg);
    void from_json(const nlohmann::json& json, Timestamp& msg);
}

#endif
