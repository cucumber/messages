#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/feature_child.hpp>

namespace cucumber::messages {

std::string
feature_child::to_string() const
{
    std::ostringstream oss;

    oss
    << "rule=" << rule
    << ", background=" << background
    << ", scenario=" << scenario
        ;

    return oss.str();
}

void
feature_child::to_json(json& j) const
{
    j[camelize("feature_child")] = json{
        { camelize("rule"), rule },
        { camelize("background"), background },
        { camelize("scenario"), scenario }
    };
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
