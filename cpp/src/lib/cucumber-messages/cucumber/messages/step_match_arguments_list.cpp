#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/step_match_arguments_list.hpp>

namespace cucumber::messages {

std::string
step_match_arguments_list::to_string() const
{
    std::ostringstream oss;

    oss
    << "step_match_arguments=" << step_match_arguments
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const step_match_arguments_list& msg)
{
    os << msg.to_string();

    return os;
}

}
