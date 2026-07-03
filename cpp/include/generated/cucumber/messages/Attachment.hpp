#ifndef CUCUMBER_MESSAGES_ATTACHMENT_HPP
#define CUCUMBER_MESSAGES_ATTACHMENT_HPP

#include "cucumber/messages/AttachmentContentEncoding.hpp"
#include "cucumber/messages/Source.hpp"
#include "cucumber/messages/Timestamp.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the Attachment message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Attachments (parse errors, execution errors, screenshots, links...)
    //
    // An attachment represents any kind of data associated with a line in a
    // [Source](#io.cucumber.messages.Source) file. It can be used for:
    //
    // * Syntax errors during parse time
    // * Screenshots captured and attached during execution
    // * Logs captured and attached during execution
    //
    // It is not to be used for runtime errors raised/thrown during execution. This
    // is captured in `TestResult`.
    //
    // Generated code

    struct Attachment
    {
        std::string body;
        AttachmentContentEncoding contentEncoding;
        std::optional<std::string> fileName;
        std::string mediaType;
        std::optional<std::shared_ptr<Source>> source;
        std::optional<std::string> testCaseStartedId;
        std::optional<std::string> testStepId;
        std::optional<std::string> url;
        std::optional<std::string> testRunStartedId;
        std::optional<std::string> testRunHookStartedId;
        std::optional<std::shared_ptr<Timestamp>> timestamp;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const Attachment& msg);

    void to_json(nlohmann::json& json, const Attachment& msg);
    void from_json(const nlohmann::json& json, Attachment& msg);
}

#endif
