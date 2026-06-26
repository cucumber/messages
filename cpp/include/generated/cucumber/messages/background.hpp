#ifndef CUCUMBER_MESSAGES_BACKGROUND_HPP
#define CUCUMBER_MESSAGES_BACKGROUND_HPP

#include "cucumber/messages/location.hpp"
#include "cucumber/messages/step.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

namespace cucumber::messages
{
    //
    // Represents the Background message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct background
    {
        using shared_ptr = background;//std::shared_ptr<background>;

        cucumber::messages::location::shared_ptr location;
        std::string keyword;
        std::string name;
        std::string description;
        std::vector<cucumber::messages::step::shared_ptr> steps;
        std::string id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const background& msg);

    void to_json(nlohmann::json& json, const background& msg);
    void from_json(const nlohmann::json& json, background& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<background>& msg);

}

#endif
