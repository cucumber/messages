#include <sstream>

#include <cucumber/utils.hpp>
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

}
