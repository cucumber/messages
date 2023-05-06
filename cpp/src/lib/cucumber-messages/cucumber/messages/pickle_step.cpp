#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/pickle_step.hpp>

namespace cucumber::messages {

std::string
pickle_step::to_string() const
{
    std::ostringstream oss;

    oss
    << "argument=" << argument
    << ", ast_node_ids=" << ast_node_ids
    << ", id=" << id
    << ", type=" << type
    << ", text=" << text
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const pickle_step& msg)
{
    os << msg.to_string();

    return os;
}

}
