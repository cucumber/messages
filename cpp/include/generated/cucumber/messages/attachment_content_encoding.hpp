#ifndef CUCUMBER_MESSAGES_ATTACHMENT_CONTENT_ENCODING_HPP
#define CUCUMBER_MESSAGES_ATTACHMENT_CONTENT_ENCODING_HPP

#include "nlohmann/json_fwd.hpp"
#include <cstdint>
#include <ostream>
#include <string_view>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    enum class attachment_content_encoding : std::uint_fast8_t
    {
        IDENTITY,
        BASE64,
    };

    [[nodiscard]] std::string_view to_string(attachment_content_encoding value);

    std::ostream& operator<<(std::ostream& stream, attachment_content_encoding value);

    void to_json(nlohmann::json& json, const attachment_content_encoding& msg);
}

#endif
