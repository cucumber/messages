#ifndef CUCUMBER_MESSAGES_TABLEROW_HPP
#define CUCUMBER_MESSAGES_TABLEROW_HPP

#include "cucumber/messages/TableCell.hpp"
#include "cucumber/messages/Location.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <ostream>
#include <string>
#include <vector>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the TableRow message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A row in a table
    //
    // Generated code

    struct TableRow
    {
        std::shared_ptr<Location> location;
        std::vector<std::shared_ptr<TableCell>> cells;
        std::string id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const TableRow& msg);

    void to_json(nlohmann::json& json, const TableRow& msg);
    void from_json(const nlohmann::json& json, TableRow& msg);
}

#endif
