#ifndef CUCUMBER_MESSAGES_TAG_HPP
#define CUCUMBER_MESSAGES_TAG_HPP

#include "cucumber/messages/Location.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Tag message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A tag
    //
    // Generated code

    struct Tag
    {
        std::shared_ptr<Location> location;
        std::string name;
        std::string id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Tag& msg);

    void to_json(nlohmann::json& json, const Tag& msg);
    void from_json(const nlohmann::json& json, Tag& msg);
}

#endif
