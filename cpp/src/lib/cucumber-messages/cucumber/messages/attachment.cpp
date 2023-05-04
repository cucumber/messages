#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/attachment.hpp>

namespace cucumber::messages {

std::string
attachment::to_string() const
{
    std::ostringstream oss;

    oss
        << "body=" << body
        << ", content_encoding=" << content_encoding
        << ", file_name=" << file_name
        << ", media_type=" << media_type
        << ", source=" << source
        << ", test_case_started_id=" << test_case_started_id
        << ", test_step_id=" << test_step_id
        << ", url=" << url
        ;

    return oss.str();
}

}
