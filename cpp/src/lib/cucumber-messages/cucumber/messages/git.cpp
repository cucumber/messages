#include <sstream>

#include <cucumber/utils.hpp>
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

}
