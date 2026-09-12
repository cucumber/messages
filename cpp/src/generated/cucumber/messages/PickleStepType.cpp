#include "cucumber/messages/PickleStepType.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <iostream>
#include <string_view>
#include <unordered_map>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    std::string_view to_string(PickleStepType value)
    {
        using map_type = std::unordered_map<PickleStepType, std::string_view>;

        static const map_type lut = {
            { PickleStepType::UNKNOWN, "Unknown" },
            { PickleStepType::CONTEXT, "Context" },
            { PickleStepType::ACTION, "Action" },
            { PickleStepType::OUTCOME, "Outcome" },
        };

        return lut.at(value);
    }

    std::ostream& operator<<(std::ostream& stream, PickleStepType value)
    {
        stream << to_string(value);

        return stream;
    }

    void to_json(nlohmann::json& json, const PickleStepType& msg)
    {
        json = to_string(msg);
    }

    void from_json(const nlohmann::json& json, PickleStepType& msg)
    {
        static const std::unordered_map<std::string_view, PickleStepType> lut = {
            { "Unknown", PickleStepType::UNKNOWN },
            { "Context", PickleStepType::CONTEXT },
            { "Action", PickleStepType::ACTION },
            { "Outcome", PickleStepType::OUTCOME },
        };

        msg = lut.at(json.get<std::string_view>());
    }
}

