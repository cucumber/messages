#ifndef CUCUMBER_MESSAGES_META_HPP
#define CUCUMBER_MESSAGES_META_HPP

#include "cucumber/messages/ci.hpp"
#include "cucumber/messages/product.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the Meta message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // This message contains meta information about the environment. Consumers can use
    // this for various purposes.
    //
    // Generated code

    struct meta
    {
        std::string protocol_version;
        cucumber::messages::product implementation;
        cucumber::messages::product runtime;
        cucumber::messages::product os;
        cucumber::messages::product cpu;
        std::optional<cucumber::messages::ci> ci;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const meta& msg);

    void to_json(nlohmann::json& json, const meta& msg);
    void from_json(const nlohmann::json& json, meta& msg);
}

#endif
