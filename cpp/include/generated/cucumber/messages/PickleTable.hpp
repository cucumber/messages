#ifndef CUCUMBER_MESSAGES_PICKLE_TABLE_HPP
#define CUCUMBER_MESSAGES_PICKLE_TABLE_HPP

#include "cucumber/messages/PickleTableRow.hpp"
#include "nlohmann/json_fwd.hpp"
#include <cstddef>
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the PickleTable message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct PickleTable
    {
        std::optional<std::size_t> argumentIndex;
        std::vector<std::shared_ptr<PickleTableRow>> rows;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const PickleTable& msg);

    void to_json(nlohmann::json& json, const PickleTable& msg);
    void from_json(const nlohmann::json& json, PickleTable& msg);
}

#endif
