#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/global_hook_started.hpp>

namespace cucumber::messages {

std::string
global_hook_started::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "test_run_started_id=", test_run_started_id);
    cucumber::messages::to_string(oss, ", hook_id=", hook_id);
    cucumber::messages::to_string(oss, ", timestamp=", timestamp);

    return oss.str();
}

void
global_hook_started::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("test_run_started_id"), test_run_started_id);
    cucumber::messages::to_json(j, camelize("hook_id"), hook_id);
    cucumber::messages::to_json(j, camelize("timestamp"), timestamp);
}

std::string
global_hook_started::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const global_hook_started& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const global_hook_started& m)
{ m.to_json(j); }

}
