#ifndef CUCUMBER_MESSAGES_PICKLETABLEROW_HPP
#define CUCUMBER_MESSAGES_PICKLETABLEROW_HPP

#include "cucumber/messages/PickleTableCell.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <ostream>
#include <string>
#include <vector>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the PickleTableRow message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct PickleTableRow
    {
        std::vector<std::shared_ptr<PickleTableCell>> cells;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const PickleTableRow& msg);

    void to_json(nlohmann::json& json, const PickleTableRow& msg);
    void from_json(const nlohmann::json& json, PickleTableRow& msg);
}

#endif
