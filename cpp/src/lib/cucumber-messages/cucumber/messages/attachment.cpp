#include <sstream>

#include <cucumber/messages/utils.hpp>
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

std::ostream&
operator<<(std::ostream& os, const attachment& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const attachment& m)
{
    j = json{
        { "body", m.body },
        { "content_encoding", m.content_encoding },
        { "file_name", m.file_name },
        { "media_type", m.media_type },
        { "source", m.source },
        { "test_case_started_id", m.test_case_started_id },
        { "test_step_id", m.test_step_id },
        { "url", m.url }
    };
}

}
