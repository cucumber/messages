#ifndef CUCUMBER_MESSAGES_META_HPP
#define CUCUMBER_MESSAGES_META_HPP

#include "cucumber/messages/Ci.hpp"
#include "cucumber/messages/Product.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

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

    struct Meta
    {
        std::string protocolVersion;
        std::shared_ptr<Product> implementation;
        std::shared_ptr<Product> runtime;
        std::shared_ptr<Product> os;
        std::shared_ptr<Product> cpu;
        std::optional<std::shared_ptr<Ci>> ci;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Meta& msg);

    void to_json(nlohmann::json& json, const Meta& msg);
    void from_json(const nlohmann::json& json, Meta& msg);
}

#endif
