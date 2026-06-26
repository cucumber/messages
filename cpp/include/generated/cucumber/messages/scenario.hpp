#ifndef CUCUMBER_MESSAGES_SCENARIO_HPP
#define CUCUMBER_MESSAGES_SCENARIO_HPP

#include "cucumber/messages/examples.hpp"
#include "cucumber/messages/location.hpp"
#include "cucumber/messages/step.hpp"
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
    // Represents the Scenario message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct scenario
    {
        using shared_ptr = scenario;//std::shared_ptr<scenario>;

        cucumber::messages::location::shared_ptr location;
        std::vector<cucumber::messages::tag::shared_ptr> tags;
        std::string keyword;
        std::string name;
        std::string description;
        std::vector<cucumber::messages::step::shared_ptr> steps;
        std::vector<cucumber::messages::examples::shared_ptr> examples;
        std::string id;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const scenario& msg);

    void to_json(nlohmann::json& json, const scenario& msg);
    void from_json(const nlohmann::json& json, scenario& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<scenario>& msg);

}

#endif
