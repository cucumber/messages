#ifndef CUCUMBER_MESSAGES_DATATABLE_HPP
#define CUCUMBER_MESSAGES_DATATABLE_HPP

#include "cucumber/messages/Location.hpp"
#include "cucumber/messages/TableRow.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <ostream>
#include <string>
#include <vector>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the DataTable message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct DataTable
    {
        std::shared_ptr<Location> location;
        std::vector<std::shared_ptr<TableRow>> rows;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const DataTable& msg);

    void to_json(nlohmann::json& json, const DataTable& msg);
    void from_json(const nlohmann::json& json, DataTable& msg);
}

#endif
