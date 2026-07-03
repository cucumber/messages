#ifndef CUCUMBER_MESSAGES_BACKGROUND_HPP
#define CUCUMBER_MESSAGES_BACKGROUND_HPP

#include "cucumber/messages/Location.hpp"
#include "cucumber/messages/Step.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <ostream>
#include <string>
#include <vector>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Background message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct Background
    {
        std::shared_ptr<Location> location;
        std::string keyword;
        std::string name;
        std::string description;
        std::vector<std::shared_ptr<Step>> steps;
        std::string id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Background& msg);

    void to_json(nlohmann::json& json, const Background& msg);
    void from_json(const nlohmann::json& json, Background& msg);
}

#endif
