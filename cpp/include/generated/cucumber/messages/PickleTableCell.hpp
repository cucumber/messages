#ifndef CUCUMBER_MESSAGES_PICKLE_TABLE_CELL_HPP
#define CUCUMBER_MESSAGES_PICKLE_TABLE_CELL_HPP

#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the PickleTableCell message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct PickleTableCell
    {
        std::string value;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const PickleTableCell& msg);

    void to_json(nlohmann::json& json, const PickleTableCell& msg);
    void from_json(const nlohmann::json& json, PickleTableCell& msg);
}

#endif
