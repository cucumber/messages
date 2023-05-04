#include <sstream>

#include <cucumber/utils.hpp>
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

}
