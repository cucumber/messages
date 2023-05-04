#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/group.hpp>

namespace cucumber::messages {

std::string
group::to_string() const
{
    std::ostringstream oss;

    oss
        << "children=" << children
        << ", start=" << start
        << ", value=" << value
        ;

    return oss.str();
}

}
