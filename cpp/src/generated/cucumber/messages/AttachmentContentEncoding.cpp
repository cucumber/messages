#include "cucumber/messages/AttachmentContentEncoding.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <iostream>
#include <string_view>
#include <unordered_map>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    std::string_view to_string(AttachmentContentEncoding value)
    {
        using map_type = std::unordered_map<AttachmentContentEncoding, std::string_view>;

        static const map_type lut = {
            { AttachmentContentEncoding::IDENTITY, "IDENTITY" },
            { AttachmentContentEncoding::BASE64, "BASE64" },
        };

        return lut.at(value);
    }

    std::ostream& operator<<(std::ostream& stream, AttachmentContentEncoding value)
    {
        stream << to_string(value);

        return stream;
    }

    void to_json(nlohmann::json& json, const AttachmentContentEncoding& msg)
    {
        json = to_string(msg);
    }

    void from_json(const nlohmann::json& json, AttachmentContentEncoding& msg)
    {
        static const std::unordered_map<std::string_view, AttachmentContentEncoding> lut = {
            { "IDENTITY", AttachmentContentEncoding::IDENTITY },
            { "BASE64", AttachmentContentEncoding::BASE64 },
        };

        msg = lut.at(json.get<std::string_view>());
    }
}

