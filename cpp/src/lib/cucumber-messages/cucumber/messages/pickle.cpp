#include <sstream>

#include <cucumber/messages/utils.hpp>
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
    << ", ast_node_ids=" << ast_node_ids
        ;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const pickle& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const pickle& m)
{
    j = json{
        { "id", m.id },
        { "uri", m.uri },
        { "name", m.name },
        { "language", m.language },
        { "steps", m.steps },
        { "tags", m.tags },
        { "ast_node_ids", m.ast_node_ids }
    };
}

}
