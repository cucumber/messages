#ifndef CUCUMBER_MESSAGES_EXAMPLES_HPP
#define CUCUMBER_MESSAGES_EXAMPLES_HPP

#include "cucumber/messages/Location.hpp"
#include "cucumber/messages/TableRow.hpp"
#include "cucumber/messages/Tag.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Examples message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct Examples
    {
        std::shared_ptr<Location> location;
        std::vector<std::shared_ptr<Tag>> tags;
        std::string keyword;
        std::string name;
        std::string description;
        std::optional<std::shared_ptr<TableRow>> tableHeader;
        std::vector<std::shared_ptr<TableRow>> tableBody;
        std::string id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Examples& msg);

    void to_json(nlohmann::json& json, const Examples& msg);
    void from_json(const nlohmann::json& json, Examples& msg);
}

#endif
