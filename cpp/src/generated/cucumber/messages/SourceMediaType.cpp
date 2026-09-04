#include "cucumber/messages/SourceMediaType.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <iostream>
#include <string_view>
#include <unordered_map>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    std::string_view to_string(SourceMediaType value)
    {
        using map_type = std::unordered_map<SourceMediaType, std::string_view>;

        static const map_type lut = {
            { SourceMediaType::TEXT_X_CUCUMBER_GHERKIN_PLAIN, "text/x.cucumber.gherkin+plain" },
            { SourceMediaType::TEXT_X_CUCUMBER_GHERKIN_MARKDOWN, "text/x.cucumber.gherkin+markdown" },
        };

        return lut.at(value);
    }

    std::ostream& operator<<(std::ostream& stream, SourceMediaType value)
    {
        stream << to_string(value);

        return stream;
    }

    void to_json(nlohmann::json& json, const SourceMediaType& msg)
    {
        json = to_string(msg);
    }

    void from_json(const nlohmann::json& json, SourceMediaType& msg)
    {
        static const std::unordered_map<std::string_view, SourceMediaType> lut = {
            { "text/x.cucumber.gherkin+plain", SourceMediaType::TEXT_X_CUCUMBER_GHERKIN_PLAIN },
            { "text/x.cucumber.gherkin+markdown", SourceMediaType::TEXT_X_CUCUMBER_GHERKIN_MARKDOWN },
        };

        msg = lut.at(json.get<std::string_view>());
    }
}

