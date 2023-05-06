#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/test_case.hpp>

namespace cucumber::messages {

std::string
test_case::to_string() const
{
    std::ostringstream oss;

    oss
    << "id=" << id
    << ", pickle_id=" << pickle_id
    << ", test_steps=" << test_steps
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const test_case& msg)
{
    os << msg.to_string();

    return os;
}

}
