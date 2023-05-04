#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/background.hpp>

namespace cucumber::messages {

std::string
background::to_string() const
{
    std::ostringstream oss;

    oss
        << "location=" << location
        << ", keyword=" << keyword
        << ", name=" << name
        << ", description=" << description
        << ", steps=" << steps
        << ", id=" << id
        ;

    return oss.str();
}

}
