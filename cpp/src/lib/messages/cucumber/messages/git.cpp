#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/git.hpp>

namespace cucumber::messages {

std::string
git::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "remote=", remote);
    cucumber::messages::to_string(oss, ", revision=", revision);
    cucumber::messages::to_string(oss, ", branch=", branch);
    cucumber::messages::to_string(oss, ", tag=", tag);

    return oss.str();
}

void
git::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("remote"), remote);
    cucumber::messages::to_json(j, camelize("revision"), revision);
    cucumber::messages::to_json(j, camelize("branch"), branch);
    cucumber::messages::to_json(j, camelize("tag"), tag);
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
