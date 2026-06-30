#ifndef CUCUMBER_MESSAGES_PICKLE_STEP_ARGUMENT_HPP
#define CUCUMBER_MESSAGES_PICKLE_STEP_ARGUMENT_HPP

#include "cucumber/messages/pickle_table.hpp"
#include "cucumber/messages/pickle_doc_string.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the PickleStepArgument message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // An optional argument
    //
    // Generated code

    struct pickle_step_argument
    {
        std::optional<cucumber::messages::pickle_doc_string> doc_string;
        std::optional<cucumber::messages::pickle_table> data_table;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const pickle_step_argument& msg);

    void to_json(nlohmann::json& json, const pickle_step_argument& msg);
    void from_json(const nlohmann::json& json, pickle_step_argument& msg);
}

#endif
