#pragma once

#include <string>
#include <sstream>
#include <vector>

namespace cucumber {

template <typename Msg>
std::string
to_string(const std::vector<Msg>& msgs)
{
    std::ostringstream oss;

    oss << '[';

    for (std::size_t i = 0; i < msgs.size(); ++i) {
        oss << (i > 0 ? ", " : "") << msgs[i];
    }

    oss << ']';

    return oss.str();
}

}
