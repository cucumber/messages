#ifndef CUCUMBER_MESSAGES_SUGGESTION_HPP
#define CUCUMBER_MESSAGES_SUGGESTION_HPP

#include "cucumber/messages/Snippet.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <ostream>
#include <string>
#include <vector>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Suggestion message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A suggested fragment of code to implement an undefined step
    //
    // Generated code

    struct Suggestion
    {
        std::string id;
        std::string pickleStepId;
        std::vector<std::shared_ptr<Snippet>> snippets;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Suggestion& msg);

    void to_json(nlohmann::json& json, const Suggestion& msg);
    void from_json(const nlohmann::json& json, Suggestion& msg);
}

#endif
