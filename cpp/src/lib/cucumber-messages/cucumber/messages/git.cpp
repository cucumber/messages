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

void
git::to_json(json& j) const
{
    j = json{
        { "remote", remote },
        { "revision", revision },
        { "branch", branch },
        { "tag", tag }
    };
}

std::string
git::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const git& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const git& m)
{ m.to_json(j); }

}
