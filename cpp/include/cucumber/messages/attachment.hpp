#pragma once

#include <vector>

#include <cucumber/message.hpp>

#include <cucumber/messages/attachment_content_encoding.hpp>
#include <cucumber/messages/source.hpp>

namespace cucumber::messages {

//
// Represents the Attachment message in Cucumber's message protocol
// @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
//
// //// Attachments (parse errors, execution errors, screenshots, links...)
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

struct attachment : cucumber::message
{
    std::string body;
    cucumber::messages::attachment_content_encoding content_encoding;
    std::string file_name;
    std::string media_type;
    cucumber::messages::source source;
    std::string test_case_started_id;
    std::string test_step_id;
    std::string url;

    std::string to_string() const override;
};

}
