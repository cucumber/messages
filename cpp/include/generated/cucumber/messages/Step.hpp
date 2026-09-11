#ifndef CUCUMBER_MESSAGES_STEP_HPP
#define CUCUMBER_MESSAGES_STEP_HPP

#include "cucumber/messages/DataTable.hpp"
#include "cucumber/messages/DocString.hpp"
#include "cucumber/messages/StepKeywordType.hpp"
#include "cucumber/messages/Location.hpp"
#include "nlohmann/json_fwd.hpp"
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Step message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A step
    //

    struct Step
    {
        Location location;
        std::string keyword;
        std::optional<StepKeywordType> keywordType;
        std::string text;
        std::optional<DocString> docString;
        std::optional<DataTable> dataTable;
        std::string id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Step& msg);

    void to_json(nlohmann::json& json, const Step& msg);
    void from_json(const nlohmann::json& json, Step& msg);
}

#endif
