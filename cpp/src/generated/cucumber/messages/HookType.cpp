#include "cucumber/messages/HookType.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <iostream>
#include <string_view>
#include <unordered_map>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    std::string_view to_string(HookType value)
    {
        using map_type = std::unordered_map<HookType, std::string_view>;

        static const map_type lut = {
            { HookType::BEFORE_TEST_RUN, "BEFORE_TEST_RUN" },
            { HookType::AFTER_TEST_RUN, "AFTER_TEST_RUN" },
            { HookType::BEFORE_TEST_CASE, "BEFORE_TEST_CASE" },
            { HookType::AFTER_TEST_CASE, "AFTER_TEST_CASE" },
            { HookType::BEFORE_TEST_STEP, "BEFORE_TEST_STEP" },
            { HookType::AFTER_TEST_STEP, "AFTER_TEST_STEP" },
        };

        return lut.at(value);
    }

    std::ostream& operator<<(std::ostream& stream, HookType value)
    {
        stream << to_string(value);

        return stream;
    }

    void to_json(nlohmann::json& json, const HookType& msg)
    {
        json = to_string(msg);
    }

    void from_json(const nlohmann::json& json, HookType& msg)
    {
        static const std::unordered_map<std::string_view, HookType> lut = {
            { "BEFORE_TEST_RUN", HookType::BEFORE_TEST_RUN },
            { "AFTER_TEST_RUN", HookType::AFTER_TEST_RUN },
            { "BEFORE_TEST_CASE", HookType::BEFORE_TEST_CASE },
            { "AFTER_TEST_CASE", HookType::AFTER_TEST_CASE },
            { "BEFORE_TEST_STEP", HookType::BEFORE_TEST_STEP },
            { "AFTER_TEST_STEP", HookType::AFTER_TEST_STEP },
        };

        msg = lut.at(json.get<std::string_view>());
    }
}

