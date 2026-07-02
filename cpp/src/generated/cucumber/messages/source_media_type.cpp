#include "cucumber/messages/source_media_type.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <iostream>
#include <string_view>
#include <unordered_map>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    std::string_view to_string(source_media_type value)
    {
        using map_type = std::unordered_map<source_media_type, std::string_view>;

        static const map_type lut = {
            { source_media_type::TEXT_X_CUCUMBER_GHERKIN_PLAIN, "text/x.cucumber.gherkin+plain" },
            { source_media_type::TEXT_X_CUCUMBER_GHERKIN_MARKDOWN, "text/x.cucumber.gherkin+markdown" },
        };

        return lut.at(value);
    }

    std::ostream& operator<<(std::ostream& stream, source_media_type value)
    {
        stream << to_string(value);

        return stream;
    }

    void to_json(nlohmann::json& json, const source_media_type& msg)
    {
        json = to_string(msg);
    }

    void from_json(const nlohmann::json& json, source_media_type& msg)
    {
        static const std::unordered_map<std::string_view, source_media_type> lut = {
            { "text/x.cucumber.gherkin+plain", source_media_type::TEXT_X_CUCUMBER_GHERKIN_PLAIN },
            { "text/x.cucumber.gherkin+markdown", source_media_type::TEXT_X_CUCUMBER_GHERKIN_MARKDOWN },
        };

        msg = lut.at(json.get<std::string_view>());
    }
}
