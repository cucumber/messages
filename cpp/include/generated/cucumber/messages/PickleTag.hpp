#ifndef CUCUMBER_MESSAGES_PICKLE_TAG_HPP
#define CUCUMBER_MESSAGES_PICKLE_TAG_HPP

#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the PickleTag message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A tag
    //

    struct PickleTag
    {
        std::string name;
        std::string astNodeId;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const PickleTag& msg);

    void to_json(nlohmann::json& json, const PickleTag& msg);
    void from_json(const nlohmann::json& json, PickleTag& msg);
}

#endif
