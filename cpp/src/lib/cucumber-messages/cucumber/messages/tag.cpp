#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/tag.hpp>

namespace cucumber::messages {

std::string
tag::to_string() const
{
    std::ostringstream oss;

    oss
        << "location=" << location
        << ", name=" << name
        << ", id=" << id
        ;

    return oss.str();
}

}
