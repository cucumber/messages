#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/test_step_result.hpp>

namespace cucumber::messages {

std::string
test_step_result::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "duration=", duration);
    cucumber::messages::to_string(oss, ", message=", message);
    cucumber::messages::to_string(oss, ", status=", status);
    cucumber::messages::to_string(oss, ", exception=", exception);

    return oss.str();
}

void
test_step_result::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("duration"), duration);
    cucumber::messages::to_json(j, camelize("message"), message);
    cucumber::messages::to_json(j, camelize("status"), status);
    cucumber::messages::to_json(j, camelize("exception"), exception);
}

std::string
test_step_result::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const test_step_result& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const test_step_result& m)
{ m.to_json(j); }

}
