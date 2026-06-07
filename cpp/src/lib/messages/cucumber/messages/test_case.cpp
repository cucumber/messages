#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/test_case.hpp>

namespace cucumber::messages {

std::string
test_case::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "id=", id);
    cucumber::messages::to_string(oss, ", pickle_id=", pickle_id);
    cucumber::messages::to_string(oss, ", test_steps=", test_steps);
    cucumber::messages::to_string(oss, ", test_run_started_id=", test_run_started_id);

    return oss.str();
}

void
test_case::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("id"), id);
    cucumber::messages::to_json(j, camelize("pickle_id"), pickle_id);
    cucumber::messages::to_json(j, camelize("test_steps"), test_steps);
    cucumber::messages::to_json(j, camelize("test_run_started_id"), test_run_started_id);
}

std::string
test_case::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const test_case& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const test_case& m)
{ m.to_json(j); }

}
