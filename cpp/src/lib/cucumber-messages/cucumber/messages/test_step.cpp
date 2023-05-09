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

void to_json(json& j, const test_step& m)
{
    j = json{
        { "hook_id", m.hook_id },
        { "id", m.id },
        { "pickle_step_id", m.pickle_step_id },
        { "step_definition_ids", m.step_definition_ids },
        { "step_match_arguments_lists", m.step_match_arguments_lists }
    };
}

}
