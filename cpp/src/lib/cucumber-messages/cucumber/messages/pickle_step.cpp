#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/pickle_step.hpp>

namespace cucumber::messages {

std::string
pickle_step::to_string() const
{
    std::ostringstream oss;

    oss
        << "argument=" << argument
        << ", ast_node_ids=" << cucumber::to_string(ast_node_ids)
        << ", id=" << id
        << ", type=" << type
        << ", text=" << text
        ;

    return oss.str();
}

}
