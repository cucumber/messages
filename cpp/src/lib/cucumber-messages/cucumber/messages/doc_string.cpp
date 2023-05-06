#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/doc_string.hpp>

namespace cucumber::messages {

std::string
doc_string::to_string() const
{
    std::ostringstream oss;

    oss
    << "location=" << location
    << ", media_type=" << media_type
    << ", content=" << content
    << ", delimiter=" << delimiter
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const doc_string& msg)
{
    os << msg.to_string();

    return os;
}

}
