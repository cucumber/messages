#ifndef CUCUMBER_MESSAGES_TAG_HPP
#define CUCUMBER_MESSAGES_TAG_HPP

#include "cucumber/messages/location.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the Tag message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A tag
    //
    // Generated code

    struct tag
    {
        using shared_ptr = tag;//std::shared_ptr<tag>;

        cucumber::messages::location::shared_ptr location;
        std::string name;
        std::string id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const tag& msg);

    void to_json(nlohmann::json& json, const tag& msg);
    void from_json(const nlohmann::json& json, tag& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<tag>& msg);

}

#endif
