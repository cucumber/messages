#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/comment.hpp>

namespace cucumber::messages {

std::string
comment::to_string() const
{
    std::ostringstream oss;

    oss
        << "location=" << location
        << ", text=" << text
        ;

    return oss.str();
}

}
