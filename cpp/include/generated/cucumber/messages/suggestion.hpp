#ifndef CUCUMBER_MESSAGES_SUGGESTION_HPP
#define CUCUMBER_MESSAGES_SUGGESTION_HPP

#include "cucumber/messages/snippet.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

namespace cucumber::messages
{
    //
    // Represents the Suggestion message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A suggested fragment of code to implement an undefined step
    //
    // Generated code

    struct suggestion
    {
        using shared_ptr = suggestion;//std::shared_ptr<suggestion>;

        std::string id;
        std::string pickle_step_id;
        std::vector<cucumber::messages::snippet::shared_ptr> snippets;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const suggestion& msg);

    void to_json(nlohmann::json& json, const suggestion& msg);
    void from_json(const nlohmann::json& json, suggestion& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<suggestion>& msg);

}

#endif
