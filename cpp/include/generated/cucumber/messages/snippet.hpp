#ifndef CUCUMBER_MESSAGES_SNIPPET_HPP
#define CUCUMBER_MESSAGES_SNIPPET_HPP

#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the Snippet message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct snippet
    {
        using shared_ptr = snippet;//std::shared_ptr<snippet>;

        std::string language;
        std::string code;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const snippet& msg);

    void to_json(nlohmann::json& json, const snippet& msg);
    void from_json(const nlohmann::json& json, snippet& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<snippet>& msg);

}

#endif
