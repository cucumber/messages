#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/test_run_started.hpp>

namespace cucumber::messages {

std::string
test_run_started::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "timestamp=", timestamp);

    return oss.str();
}

void
test_run_started::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("timestamp"), timestamp);
}

std::string
test_run_started::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const test_run_started& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const test_run_started& m)
{ m.to_json(j); }

}
