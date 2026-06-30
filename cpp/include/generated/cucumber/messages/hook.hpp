#ifndef CUCUMBER_MESSAGES_HOOK_HPP
#define CUCUMBER_MESSAGES_HOOK_HPP

#include "cucumber/messages/source_reference.hpp"
#include "cucumber/messages/hook_type.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the Hook message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct hook
    {
        std::string id;
        std::optional<std::string> name;
        cucumber::messages::source_reference source_reference;
        std::optional<std::string> tag_expression;
        std::optional<cucumber::messages::hook_type> type;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const hook& msg);

    void to_json(nlohmann::json& json, const hook& msg);
    void from_json(const nlohmann::json& json, hook& msg);
}

#endif
