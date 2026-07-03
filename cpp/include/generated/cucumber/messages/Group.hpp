#ifndef CUCUMBER_MESSAGES_GROUP_HPP
#define CUCUMBER_MESSAGES_GROUP_HPP

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
    // Represents the Group message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct Group
    {
        std::optional<std::vector<std::shared_ptr<Group>>> children;
        std::optional<std::size_t> start;
        std::optional<std::string> value;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Group& msg);

    void to_json(nlohmann::json& json, const Group& msg);
    void from_json(const nlohmann::json& json, Group& msg);
}

#endif
