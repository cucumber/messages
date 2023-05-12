#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/pickle_tag.hpp>

namespace cucumber::messages {

std::string
pickle_tag::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "name=", name);
    cucumber::messages::to_string(oss, ", ast_node_id=", ast_node_id);

    return oss.str();
}

void
pickle_tag::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("name"), name);
    cucumber::messages::to_json(j, camelize("ast_node_id"), ast_node_id);
}

std::string
pickle_tag::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const pickle_tag& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const pickle_tag& m)
{ m.to_json(j); }

}
