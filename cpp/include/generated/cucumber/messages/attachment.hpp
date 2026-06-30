#ifndef CUCUMBER_MESSAGES_ATTACHMENT_HPP
#define CUCUMBER_MESSAGES_ATTACHMENT_HPP

#include "cucumber/messages/attachment_content_encoding.hpp"
#include "cucumber/messages/source.hpp"
#include "cucumber/messages/timestamp.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

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

    struct attachment
    {
        std::string body;
        cucumber::messages::attachment_content_encoding content_encoding;
        std::optional<std::string> file_name;
        std::string media_type;
        std::optional<cucumber::messages::source> source;
        std::optional<std::string> test_case_started_id;
        std::optional<std::string> test_step_id;
        std::optional<std::string> url;
        std::optional<std::string> test_run_started_id;
        std::optional<std::string> test_run_hook_started_id;
        std::optional<cucumber::messages::timestamp> timestamp;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const attachment& msg);

    void to_json(nlohmann::json& json, const attachment& msg);
    void from_json(const nlohmann::json& json, attachment& msg);
}

#endif
