#ifndef CUCUMBER_MESSAGES_GHERKIN_DOCUMENT_HPP
#define CUCUMBER_MESSAGES_GHERKIN_DOCUMENT_HPP

#include "cucumber/messages/Comment.hpp"
#include "cucumber/messages/Feature.hpp"
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
    // Represents the GherkinDocument message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // The [AST](https://en.wikipedia.org/wiki/Abstract_syntax_tree) of a Gherkin document.
    // Cucumber implementations should *not* depend on `GherkinDocument` or any of its
    // children for execution - use [Pickle](#io.cucumber.messages.Pickle) instead.
    //
    // The only consumers of `GherkinDocument` should only be formatters that produce
    // "rich" output, resembling the original Gherkin document.
    //
    // Generated code

    struct GherkinDocument
    {
        std::optional<std::string> uri;
        std::optional<std::shared_ptr<Feature>> feature;
        std::vector<std::shared_ptr<Comment>> comments;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const GherkinDocument& msg);

    void to_json(nlohmann::json& json, const GherkinDocument& msg);
    void from_json(const nlohmann::json& json, GherkinDocument& msg);
}

#endif
