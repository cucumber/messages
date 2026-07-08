#ifndef CUCUMBER_MESSAGES_EXTERNAL_ATTACHMENT_HPP
#define CUCUMBER_MESSAGES_EXTERNAL_ATTACHMENT_HPP

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
    // Represents the ExternalAttachment message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Represents an attachment that is stored externally rather than embedded in the message stream.
    //
    // This message type is used for large attachments (e.g., video files) that are already
    // on the filesystem and should not be loaded into memory. Instead of embedding the content,
    // only a URL reference is stored.
    //
    // A formatter or other consumer of messages may replace an Attachment with an ExternalAttachment if it makes sense to do so.
    //
    // Generated code

    struct ExternalAttachment
    {
        std::string url;
        std::string mediaType;
        std::optional<std::string> testCaseStartedId;
        std::optional<std::string> testStepId;
        std::optional<std::string> testRunHookStartedId;
        std::optional<std::shared_ptr<Timestamp>> timestamp;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const ExternalAttachment& msg);

    void to_json(nlohmann::json& json, const ExternalAttachment& msg);
    void from_json(const nlohmann::json& json, ExternalAttachment& msg);
}

#endif
