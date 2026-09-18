#include "cucumber/messages/StepDefinitionPatternType.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <iostream>
#include <string_view>
#include <unordered_map>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    std::string_view to_string(StepDefinitionPatternType value)
    {
        using map_type = std::unordered_map<StepDefinitionPatternType, std::string_view>;

        static const map_type lut = {
            { StepDefinitionPatternType::CUCUMBER_EXPRESSION, "CUCUMBER_EXPRESSION" },
            { StepDefinitionPatternType::REGULAR_EXPRESSION, "REGULAR_EXPRESSION" },
        };

        return lut.at(value);
    }

    std::ostream& operator<<(std::ostream& stream, StepDefinitionPatternType value)
    {
        stream << to_string(value);

        return stream;
    }

    void to_json(nlohmann::json& json, const StepDefinitionPatternType& msg)
    {
        json = to_string(msg);
    }

    void from_json(const nlohmann::json& json, StepDefinitionPatternType& msg)
    {
        static const std::unordered_map<std::string_view, StepDefinitionPatternType> lut = {
            { "CUCUMBER_EXPRESSION", StepDefinitionPatternType::CUCUMBER_EXPRESSION },
            { "REGULAR_EXPRESSION", StepDefinitionPatternType::REGULAR_EXPRESSION },
        };

        msg = lut.at(json.get<std::string_view>());
    }
}

