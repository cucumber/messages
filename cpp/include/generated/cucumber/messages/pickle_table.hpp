#ifndef CUCUMBER_MESSAGES_PICKLE_TABLE_HPP
#define CUCUMBER_MESSAGES_PICKLE_TABLE_HPP

#include "cucumber/messages/pickle_table_row.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

namespace cucumber::messages
{
    //
    // Represents the PickleTable message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct pickle_table
    {
        using shared_ptr = pickle_table;//std::shared_ptr<pickle_table>;

        std::vector<cucumber::messages::pickle_table_row::shared_ptr> rows;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const pickle_table& msg);

    void to_json(nlohmann::json& json, const pickle_table& msg);
    void from_json(const nlohmann::json& json, pickle_table& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<pickle_table>& msg);

}

#endif
