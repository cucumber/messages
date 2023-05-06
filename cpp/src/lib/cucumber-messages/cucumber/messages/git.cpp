#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/git.hpp>

namespace cucumber::messages {

std::string
git::to_string() const
{
    std::ostringstream oss;

    oss
    << "remote=" << remote
    << ", revision=" << revision
    << ", branch=" << branch
    << ", tag=" << tag
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const git& msg)
{
    os << msg.to_string();

    return os;
}

}
