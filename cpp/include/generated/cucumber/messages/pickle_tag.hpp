#ifndef CUCUMBER_MESSAGES_PICKLE_TAG_HPP
#define CUCUMBER_MESSAGES_PICKLE_TAG_HPP

#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the PickleTag message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A tag
    //
    // Generated code

    struct pickle_tag
    {
        std::string name;
        std::string ast_node_id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const pickle_tag& msg);

    void to_json(nlohmann::json& json, const pickle_tag& msg);
    void from_json(const nlohmann::json& json, pickle_tag& msg);
}

#endif
