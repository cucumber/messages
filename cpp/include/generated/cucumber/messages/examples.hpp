#ifndef CUCUMBER_MESSAGES_EXAMPLES_HPP
#define CUCUMBER_MESSAGES_EXAMPLES_HPP

#include "cucumber/messages/location.hpp"
#include "cucumber/messages/table_row.hpp"
#include "cucumber/messages/tag.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

namespace cucumber::messages
{
    //
    // Represents the Examples message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct examples
    {
        using shared_ptr = examples;//std::shared_ptr<examples>;

        cucumber::messages::location::shared_ptr location;
        std::vector<cucumber::messages::tag::shared_ptr> tags;
        std::string keyword;
        std::string name;
        std::string description;
        std::optional<cucumber::messages::table_row::shared_ptr> table_header;
        std::vector<cucumber::messages::table_row::shared_ptr> table_body;
        std::string id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const examples& msg);

    void to_json(nlohmann::json& json, const examples& msg);
    void from_json(const nlohmann::json& json, examples& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<examples>& msg);

}

#endif
