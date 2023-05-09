#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/pickle_doc_string.hpp>

namespace cucumber::messages {

std::string
pickle_doc_string::to_string() const
{
    std::ostringstream oss;

    oss
    << "media_type=" << media_type
    << ", content=" << content
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const pickle_doc_string& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const pickle_doc_string& m)
{
    j = json{
        { "media_type", m.media_type },
        { "content", m.content }
    };
}

}
