#ifndef CUCUMBER_MESSAGES_TABLE_CELL_HPP
#define CUCUMBER_MESSAGES_TABLE_CELL_HPP

#include "cucumber/messages/location.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the TableCell message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A cell in a `TableRow`
    //
    // Generated code

    struct table_cell
    {
        using shared_ptr = table_cell;//std::shared_ptr<table_cell>;

        cucumber::messages::location::shared_ptr location;
        std::string value;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const table_cell& msg);

    void to_json(nlohmann::json& json, const table_cell& msg);
    void from_json(const nlohmann::json& json, table_cell& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<table_cell>& msg);

}

#endif
