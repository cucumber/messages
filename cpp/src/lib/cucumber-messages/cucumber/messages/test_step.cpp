#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/test_step.hpp>

namespace cucumber::messages {

std::string
test_step::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "hook_id=", hook_id);
    cucumber::messages::to_string(oss, ", id=", id);
    cucumber::messages::to_string(oss, ", pickle_step_id=", pickle_step_id);
    cucumber::messages::to_string(oss, ", step_definition_ids=", step_definition_ids);
    cucumber::messages::to_string(oss, ", step_match_arguments_lists=", step_match_arguments_lists);

    return oss.str();
}

void
test_step::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("hook_id"), hook_id);
    cucumber::messages::to_json(j, camelize("id"), id);
    cucumber::messages::to_json(j, camelize("pickle_step_id"), pickle_step_id);
    cucumber::messages::to_json(j, camelize("step_definition_ids"), step_definition_ids);
    cucumber::messages::to_json(j, camelize("step_match_arguments_lists"), step_match_arguments_lists);
}

std::string
test_step::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const test_step& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const test_step& m)
{ m.to_json(j); }

}
