#ifndef CUCUMBER_MESSAGES_DOC_STRING_HPP
#define CUCUMBER_MESSAGES_DOC_STRING_HPP

#include "cucumber/messages/location.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the DocString message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct doc_string
    {
        using shared_ptr = doc_string;//std::shared_ptr<doc_string>;

        cucumber::messages::location::shared_ptr location;
        std::optional<std::string> media_type;
        std::string content;
        std::string delimiter;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const doc_string& msg);

    void to_json(nlohmann::json& json, const doc_string& msg);
    void from_json(const nlohmann::json& json, doc_string& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<doc_string>& msg);

}

#endif
