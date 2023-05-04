#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/feature.hpp>

namespace cucumber::messages {

std::string
feature::to_string() const
{
    std::ostringstream oss;

    oss
        << "location=" << location
        << ", tags=" << tags
        << ", language=" << language
        << ", keyword=" << keyword
        << ", name=" << name
        << ", description=" << description
        << ", children=" << children
        ;

    return oss.str();
}

}
