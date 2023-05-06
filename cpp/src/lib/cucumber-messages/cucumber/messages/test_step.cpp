#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/test_step.hpp>

namespace cucumber::messages {

std::string
test_step::to_string() const
{
    std::ostringstream oss;

    oss
    << "hook_id=" << hook_id
    << ", id=" << id
    << ", pickle_step_id=" << pickle_step_id
    << ", step_definition_ids=" << step_definition_ids
    << ", step_match_arguments_lists=" << step_match_arguments_lists
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const test_step& msg)
{
    os << msg.to_string();

    return os;
}

}
