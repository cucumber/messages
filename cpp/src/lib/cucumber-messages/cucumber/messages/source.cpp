#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/source.hpp>

namespace cucumber::messages {

std::string
source::to_string() const
{
    std::ostringstream oss;

    oss
        << "uri=" << uri
        << ", data=" << data
        << ", media_type=" << media_type
        ;

    return oss.str();
}

}
