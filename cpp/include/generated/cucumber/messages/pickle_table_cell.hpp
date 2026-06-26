#ifndef CUCUMBER_MESSAGES_PICKLE_TABLE_CELL_HPP
#define CUCUMBER_MESSAGES_PICKLE_TABLE_CELL_HPP

#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the PickleTableCell message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct pickle_table_cell
    {
        using shared_ptr = pickle_table_cell;//std::shared_ptr<pickle_table_cell>;

        std::string value;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const pickle_table_cell& msg);

    void to_json(nlohmann::json& json, const pickle_table_cell& msg);
    void from_json(const nlohmann::json& json, pickle_table_cell& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<pickle_table_cell>& msg);

}

#endif
