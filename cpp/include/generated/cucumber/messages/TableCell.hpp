#ifndef CUCUMBER_MESSAGES_TABLECELL_HPP
#define CUCUMBER_MESSAGES_TABLECELL_HPP

#include "cucumber/messages/Location.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the TableCell message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A cell in a `TableRow`
    //
    // Generated code

    struct TableCell
    {
        std::shared_ptr<Location> location;
        std::string value;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const TableCell& msg);

    void to_json(nlohmann::json& json, const TableCell& msg);
    void from_json(const nlohmann::json& json, TableCell& msg);
}

#endif
