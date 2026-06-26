#ifndef CUCUMBER_MESSAGES_PRODUCT_HPP
#define CUCUMBER_MESSAGES_PRODUCT_HPP

#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the Product message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Used to describe various properties of Meta
    //
    // Generated code

    struct product
    {
        using shared_ptr = product;//std::shared_ptr<product>;

        std::string name;
        std::optional<std::string> version;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const product& msg);

    void to_json(nlohmann::json& json, const product& msg);
    void from_json(const nlohmann::json& json, product& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<product>& msg);

}

#endif
