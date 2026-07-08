#ifndef CUCUMBER_MESSAGES_SOURCE_REFERENCE_HPP
#define CUCUMBER_MESSAGES_SOURCE_REFERENCE_HPP

#include "cucumber/messages/JavaMethod.hpp"
#include "cucumber/messages/JavaStackTraceElement.hpp"
#include "cucumber/messages/Location.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the SourceReference message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Points to a [Source](#io.cucumber.messages.Source) identified by `uri` and a
    // [Location](#io.cucumber.messages.Location) within that file.
    //
    // Generated code

    struct SourceReference
    {
        std::optional<std::string> uri;
        std::optional<std::shared_ptr<JavaMethod>> javaMethod;
        std::optional<std::shared_ptr<JavaStackTraceElement>> javaStackTraceElement;
        std::optional<std::shared_ptr<Location>> location;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const SourceReference& msg);

    void to_json(nlohmann::json& json, const SourceReference& msg);
    void from_json(const nlohmann::json& json, SourceReference& msg);
}

#endif
