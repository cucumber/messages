#ifndef CUCUMBER_MESSAGES_SOURCE_MEDIA_TYPE_HPP
#define CUCUMBER_MESSAGES_SOURCE_MEDIA_TYPE_HPP

#include "nlohmann/json_fwd.hpp"
#include <cstdint>
#include <ostream>
#include <string_view>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    enum class source_media_type : std::uint_fast8_t
    {
        TEXT_X_CUCUMBER_GHERKIN_PLAIN,
        TEXT_X_CUCUMBER_GHERKIN_MARKDOWN,
    };

    [[nodiscard]] std::string_view to_string(source_media_type value);

    std::ostream& operator<<(std::ostream& stream, source_media_type value);

    void to_json(nlohmann::json& json, const source_media_type& msg);
}

#endif
