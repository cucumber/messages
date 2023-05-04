#include <unordered_map>

#include <cucumber/messages/attachment_content_encoding.hpp>

namespace cucumber::messages {

std::string_view
to_string(attachment_content_encoding v)
{
    using map_type = std::unordered_map<attachment_content_encoding, std::string_view>;

    static const map_type m = {
        { IDENTITY, "IDENTITY" },
        { BASE64, "BASE64" }
    };

    return m.at(v);
}

std::ostream&
operator<<(std::ostream& os, attachment_content_encoding v)
{
    os << to_string(v);

    return os;
}

}
