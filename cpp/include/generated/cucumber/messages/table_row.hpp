#ifndef CUCUMBER_MESSAGES_TABLE_ROW_HPP
#define CUCUMBER_MESSAGES_TABLE_ROW_HPP

#include "cucumber/messages/table_cell.hpp"
#include "cucumber/messages/location.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

namespace cucumber::messages
{
    //
    // Represents the TableRow message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A row in a table
    //
    // Generated code

    struct table_row
    {
        using shared_ptr = table_row;//std::shared_ptr<table_row>;

        cucumber::messages::location::shared_ptr location;
        std::vector<cucumber::messages::table_cell::shared_ptr> cells;
        std::string id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const table_row& msg);

    void to_json(nlohmann::json& json, const table_row& msg);
    void from_json(const nlohmann::json& json, table_row& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<table_row>& msg);

}

#endif
