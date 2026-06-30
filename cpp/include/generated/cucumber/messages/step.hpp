#ifndef CUCUMBER_MESSAGES_STEP_HPP
#define CUCUMBER_MESSAGES_STEP_HPP

#include "cucumber/messages/data_table.hpp"
#include "cucumber/messages/doc_string.hpp"
#include "cucumber/messages/step_keyword_type.hpp"
#include "cucumber/messages/location.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the Step message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A step
    //
    // Generated code

    struct step
    {
        cucumber::messages::location location;
        std::string keyword;
        std::optional<cucumber::messages::step_keyword_type> keyword_type;
        std::string text;
        std::optional<cucumber::messages::doc_string> doc_string;
        std::optional<cucumber::messages::data_table> data_table;
        std::string id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const step& msg);

    void to_json(nlohmann::json& json, const step& msg);
    void from_json(const nlohmann::json& json, step& msg);
}

#endif
