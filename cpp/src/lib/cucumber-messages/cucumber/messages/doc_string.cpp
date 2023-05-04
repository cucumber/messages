#include <sstream>

#include <cucumber/utils.hpp>
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

}
