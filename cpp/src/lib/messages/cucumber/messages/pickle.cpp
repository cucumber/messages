#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/pickle.hpp>

namespace cucumber::messages {

std::string
pickle::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "id=", id);
    cucumber::messages::to_string(oss, ", uri=", uri);
    cucumber::messages::to_string(oss, ", location=", location);
    cucumber::messages::to_string(oss, ", name=", name);
    cucumber::messages::to_string(oss, ", language=", language);
    cucumber::messages::to_string(oss, ", steps=", steps);
    cucumber::messages::to_string(oss, ", tags=", tags);
    cucumber::messages::to_string(oss, ", ast_node_ids=", ast_node_ids);

    return oss.str();
}

void
pickle::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("id"), id);
    cucumber::messages::to_json(j, camelize("uri"), uri);
    cucumber::messages::to_json(j, camelize("location"), location);
    cucumber::messages::to_json(j, camelize("name"), name);
    cucumber::messages::to_json(j, camelize("language"), language);
    cucumber::messages::to_json(j, camelize("steps"), steps);
    cucumber::messages::to_json(j, camelize("tags"), tags);
    cucumber::messages::to_json(j, camelize("ast_node_ids"), ast_node_ids);
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
