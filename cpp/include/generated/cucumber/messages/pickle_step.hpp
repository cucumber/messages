#ifndef CUCUMBER_MESSAGES_PICKLE_STEP_HPP
#define CUCUMBER_MESSAGES_PICKLE_STEP_HPP

#include "cucumber/messages/pickle_step_argument.hpp"
#include "cucumber/messages/pickle_step_type.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

namespace cucumber::messages
{
    //
    // Represents the PickleStep message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // An executable step
    //
    // Generated code

    struct pickle_step
    {
        std::optional<cucumber::messages::pickle_step_argument> argument;
        std::vector<std::string> ast_node_ids;
        std::string id;
        std::optional<cucumber::messages::pickle_step_type> type;
        std::string text;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const pickle_step& msg);

    void to_json(nlohmann::json& json, const pickle_step& msg);
    void from_json(const nlohmann::json& json, pickle_step& msg);
}

#endif
