#ifndef CUCUMBER_MESSAGES_LOCATION_HPP
#define CUCUMBER_MESSAGES_LOCATION_HPP

#include "nlohmann/json_fwd.hpp"
#include <cstddef>
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Location message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Points to a line and a column in a text file
    //
    // Generated code

    struct Location
    {
        std::size_t line;
        std::optional<std::size_t> column;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Location& msg);

    void to_json(nlohmann::json& json, const Location& msg);
    void from_json(const nlohmann::json& json, Location& msg);
}

#endif
