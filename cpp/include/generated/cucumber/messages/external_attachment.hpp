#ifndef CUCUMBER_MESSAGES_EXTERNAL_ATTACHMENT_HPP
#define CUCUMBER_MESSAGES_EXTERNAL_ATTACHMENT_HPP

#include "cucumber/messages/timestamp.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

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

    struct external_attachment
    {
        std::string url;
        std::string media_type;
        std::optional<std::string> test_case_started_id;
        std::optional<std::string> test_step_id;
        std::optional<std::string> test_run_hook_started_id;
        std::optional<cucumber::messages::timestamp> timestamp;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const external_attachment& msg);

    void to_json(nlohmann::json& json, const external_attachment& msg);
    void from_json(const nlohmann::json& json, external_attachment& msg);
}

#endif
