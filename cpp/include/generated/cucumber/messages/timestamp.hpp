#ifndef CUCUMBER_MESSAGES_TIMESTAMP_HPP
#define CUCUMBER_MESSAGES_TIMESTAMP_HPP

#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the Timestamp message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct timestamp
    {
        std::size_t seconds;
        std::size_t nanos;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const timestamp& msg);

    void to_json(nlohmann::json& json, const timestamp& msg);
    void from_json(const nlohmann::json& json, timestamp& msg);
}

#endif
