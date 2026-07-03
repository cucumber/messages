#ifndef CUCUMBER_MESSAGES_PICKLESTEPARGUMENT_HPP
#define CUCUMBER_MESSAGES_PICKLESTEPARGUMENT_HPP

#include "cucumber/messages/PickleTable.hpp"
#include "cucumber/messages/PickleDocString.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the PickleStepArgument message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Optional arguments. Either a PickleDocString, PickleTable or both
    //
    // Generated code

    struct PickleStepArgument
    {
        std::optional<std::shared_ptr<PickleDocString>> docString;
        std::optional<std::shared_ptr<PickleTable>> dataTable;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const PickleStepArgument& msg);

    void to_json(nlohmann::json& json, const PickleStepArgument& msg);
    void from_json(const nlohmann::json& json, PickleStepArgument& msg);
}

#endif
