#ifndef CUCUMBER_MESSAGES_PICKLE_HPP
#define CUCUMBER_MESSAGES_PICKLE_HPP

#include "cucumber/messages/Location.hpp"
#include "cucumber/messages/PickleStep.hpp"
#include "cucumber/messages/PickleTag.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Pickle message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // A `Pickle` represents a template for a `TestCase`. It is typically derived
    // from another format, such as [GherkinDocument](#io.cucumber.messages.GherkinDocument).
    // In the future a `Pickle` may be derived from other formats such as Markdown or
    // Excel files.
    //
    // By making `Pickle` the main data structure Cucumber uses for execution, the
    // implementation of Cucumber itself becomes simpler, as it doesn't have to deal
    // with the complex structure of a [GherkinDocument](#io.cucumber.messages.GherkinDocument).
    //
    // Each `PickleStep` of a `Pickle` is matched with a `StepDefinition` to create a `TestCase`
    //
    // Generated code

    struct Pickle
    {
        std::string id;
        std::string uri;
        std::optional<std::shared_ptr<Location>> location;
        std::string name;
        std::string language;
        std::vector<std::shared_ptr<PickleStep>> steps;
        std::vector<std::shared_ptr<PickleTag>> tags;
        std::vector<std::string> astNodeIds;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Pickle& msg);

    void to_json(nlohmann::json& json, const Pickle& msg);
    void from_json(const nlohmann::json& json, Pickle& msg);
}

#endif
