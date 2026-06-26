#include "cucumber/messages/attachment_content_encoding.hpp"
#include <iostream>
#include <string_view>
#include <unordered_map>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    std::string_view to_string(attachment_content_encoding value)
    {
        using map_type = std::unordered_map<attachment_content_encoding, std::string_view>;

        static const map_type lut = {
            { attachment_content_encoding::IDENTITY, "IDENTITY" },
            { attachment_content_encoding::BASE64, "BASE64" },
        };

        return lut.at(value);
    }

    std::ostream& operator<<(std::ostream& stream, attachment_content_encoding value)
    {
        stream << to_string(value);

        return stream;
    }
}
