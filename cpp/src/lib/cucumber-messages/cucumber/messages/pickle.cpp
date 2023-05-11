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

void
pickle::to_json(json& j) const
{
    j = json{
        { camelize("id"), id },
        { camelize("uri"), uri },
        { camelize("name"), name },
        { camelize("language"), language },
        { camelize("steps"), steps },
        { camelize("tags"), tags },
        { camelize("ast_node_ids"), ast_node_ids }
    };
}

std::string
pickle::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const pickle& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const pickle& m)
{ m.to_json(j); }

}
