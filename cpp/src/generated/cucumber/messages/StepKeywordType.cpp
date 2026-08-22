#include "cucumber/messages/StepKeywordType.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <iostream>
#include <string_view>
#include <unordered_map>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    std::string_view to_string(StepKeywordType value)
    {
        using map_type = std::unordered_map<StepKeywordType, std::string_view>;

        static const map_type lut = {
            { StepKeywordType::UNKNOWN, "Unknown" },
            { StepKeywordType::CONTEXT, "Context" },
            { StepKeywordType::ACTION, "Action" },
            { StepKeywordType::OUTCOME, "Outcome" },
            { StepKeywordType::CONJUNCTION, "Conjunction" },
        };

        return lut.at(value);
    }

    std::ostream& operator<<(std::ostream& stream, StepKeywordType value)
    {
        stream << to_string(value);

        return stream;
    }

    void to_json(nlohmann::json& json, const StepKeywordType& msg)
    {
        json = to_string(msg);
    }

    void from_json(const nlohmann::json& json, StepKeywordType& msg)
    {
        static const std::unordered_map<std::string_view, StepKeywordType> lut = {
            { "Unknown", StepKeywordType::UNKNOWN },
            { "Context", StepKeywordType::CONTEXT },
            { "Action", StepKeywordType::ACTION },
            { "Outcome", StepKeywordType::OUTCOME },
            { "Conjunction", StepKeywordType::CONJUNCTION },
        };

        msg = lut.at(json.get<std::string_view>());
    }
}

