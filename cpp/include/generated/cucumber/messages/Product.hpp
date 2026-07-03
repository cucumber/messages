#ifndef CUCUMBER_MESSAGES_PRODUCT_HPP
#define CUCUMBER_MESSAGES_PRODUCT_HPP

#include "nlohmann/json_fwd.hpp"
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Product message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Used to describe various properties of Meta
    //
    // Generated code

    struct Product
    {
        std::string name;
        std::optional<std::string> version;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Product& msg);

    void to_json(nlohmann::json& json, const Product& msg);
    void from_json(const nlohmann::json& json, Product& msg);
}

#endif
