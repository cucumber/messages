#include <sstream>

#include <cucumber/utils.hpp>
#include <cucumber/messages/pickle.hpp>

namespace cucumber::messages {

std::string
pickle::to_string() const
{
    std::ostringstream oss;

    oss
        << "id=" << id
        << ", uri=" << uri
        << ", name=" << name
        << ", language=" << language
        << ", steps=" << steps
        << ", tags=" << tags
        << ", ast_node_ids=" << cucumber::to_string(ast_node_ids)
        ;

    return oss.str();
}

}
