#pragma once

#include <ostream>
#include <vector>

namespace cucumber::messages {

template <typename Msg>
std::ostream&
operator<<(std::ostream& os, const std::vector<Msg>& msgs)
{
    os << '[';

    for (std::size_t i = 0; i < msgs.size(); ++i) {
        os << (i > 0 ? ", " : "") << msgs[i];
    }

    os << ']';

    return os;
}

}
