#ifndef CUCUMBER_MESSAGES_ATTACHMENT_CONTENT_ENCODING_HPP
#define CUCUMBER_MESSAGES_ATTACHMENT_CONTENT_ENCODING_HPP

#include "nlohmann/json_fwd.hpp"
#include <cstdint>
#include <ostream>
#include <string_view>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    enum class AttachmentContentEncoding : std::uint_fast8_t
    {
        IDENTITY,
        BASE64,
    };

    [[nodiscard]] std::string_view to_string(AttachmentContentEncoding value);

    std::ostream& operator<<(std::ostream& stream, AttachmentContentEncoding value);

    void to_json(nlohmann::json& json, const AttachmentContentEncoding& msg);
    void from_json(const nlohmann::json& json, AttachmentContentEncoding& msg);
}

#endif
