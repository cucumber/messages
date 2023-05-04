#include <sstream>

#include <cucumber/utils.hpp>
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

}
