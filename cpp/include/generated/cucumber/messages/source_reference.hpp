#ifndef CUCUMBER_MESSAGES_SOURCE_REFERENCE_HPP
#define CUCUMBER_MESSAGES_SOURCE_REFERENCE_HPP

#include "cucumber/messages/java_method.hpp"
#include "cucumber/messages/java_stack_trace_element.hpp"
#include "cucumber/messages/location.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

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

    struct source_reference
    {
        std::optional<std::string> uri;
        std::optional<cucumber::messages::java_method> java_method;
        std::optional<cucumber::messages::java_stack_trace_element> java_stack_trace_element;
        std::optional<cucumber::messages::location> location;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const source_reference& msg);

    void to_json(nlohmann::json& json, const source_reference& msg);
    void from_json(const nlohmann::json& json, source_reference& msg);
}

#endif
