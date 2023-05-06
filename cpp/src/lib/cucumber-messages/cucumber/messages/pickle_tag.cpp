#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/pickle_tag.hpp>

namespace cucumber::messages {

std::string
pickle_tag::to_string() const
{
    std::ostringstream oss;

    oss
    << "name=" << name
    << ", ast_node_id=" << ast_node_id
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const pickle_tag& msg)
{
    os << msg.to_string();

    return os;
}

}
