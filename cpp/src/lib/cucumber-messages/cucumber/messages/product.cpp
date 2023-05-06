#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/product.hpp>

namespace cucumber::messages {

std::string
product::to_string() const
{
    std::ostringstream oss;

    oss
    << "name=" << name
    << ", version=" << version
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const product& msg)
{
    os << msg.to_string();

    return os;
}

}
