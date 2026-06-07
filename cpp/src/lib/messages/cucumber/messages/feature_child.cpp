#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/feature_child.hpp>

namespace cucumber::messages {

std::string
feature_child::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "rule=", rule);
    cucumber::messages::to_string(oss, ", background=", background);
    cucumber::messages::to_string(oss, ", scenario=", scenario);

    return oss.str();
}

void
feature_child::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("rule"), rule);
    cucumber::messages::to_json(j, camelize("background"), background);
    cucumber::messages::to_json(j, camelize("scenario"), scenario);
}

std::string
feature_child::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const feature_child& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const feature_child& m)
{ m.to_json(j); }

}
