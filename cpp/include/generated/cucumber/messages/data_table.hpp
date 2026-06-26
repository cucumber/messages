#ifndef CUCUMBER_MESSAGES_DATA_TABLE_HPP
#define CUCUMBER_MESSAGES_DATA_TABLE_HPP

#include "cucumber/messages/location.hpp"
#include "cucumber/messages/table_row.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

namespace cucumber::messages
{
    //
    // Represents the DataTable message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct data_table
    {
        using shared_ptr = data_table;//std::shared_ptr<data_table>;

        cucumber::messages::location::shared_ptr location;
        std::vector<cucumber::messages::table_row::shared_ptr> rows;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const data_table& msg);

    void to_json(nlohmann::json& json, const data_table& msg);
    void from_json(const nlohmann::json& json, data_table& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<data_table>& msg);

}

#endif
