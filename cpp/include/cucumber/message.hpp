#pragma once

#include <type_traits>
#include <vector>
#include <string>

namespace cucumber {

struct message
{
    virtual std::string to_string() const = 0;
};

template <
    typename Msg,
    typename = std::enable_if_t<std::is_base_of_v<message, Msg>>
>
std::ostream&
operator<<(std::ostream& os, const Msg& msg)
{
    os << msg.to_string();

    return os;
}

template <
    typename Msg,
    typename = std::enable_if_t<std::is_base_of_v<message, Msg>>
>
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
