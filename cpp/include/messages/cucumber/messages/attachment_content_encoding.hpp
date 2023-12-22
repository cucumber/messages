#pragma once

#include <string_view>

namespace cucumber::messages {

enum class attachment_content_encoding
{
    IDENTITY,
    BASE64
};

std::string_view
to_string(attachment_content_encoding v);

std::ostream&
operator<<(std::ostream& os, attachment_content_encoding v);

}
