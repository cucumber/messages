#ifndef CUCUMBER_MESSAGES_PICKLE_DOC_STRING_HPP
#define CUCUMBER_MESSAGES_PICKLE_DOC_STRING_HPP

#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the PickleDocString message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct pickle_doc_string
    {
        std::optional<std::size_t> argument_index;
        std::optional<std::string> media_type;
        std::string content;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const pickle_doc_string& msg);

    void to_json(nlohmann::json& json, const pickle_doc_string& msg);
    void from_json(const nlohmann::json& json, pickle_doc_string& msg);
}

#endif
