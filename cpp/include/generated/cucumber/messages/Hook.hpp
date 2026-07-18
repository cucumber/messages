#ifndef CUCUMBER_MESSAGES_HOOK_HPP
#define CUCUMBER_MESSAGES_HOOK_HPP

#include "cucumber/messages/SourceReference.hpp"
#include "cucumber/messages/HookType.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Hook message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //

    struct Hook
    {
        std::string id;
        std::optional<std::string> name;
        std::shared_ptr<SourceReference> sourceReference;
        std::optional<std::string> tagExpression;
        std::optional<HookType> type;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Hook& msg);

    void to_json(nlohmann::json& json, const Hook& msg);
    void from_json(const nlohmann::json& json, Hook& msg);
}

#endif
