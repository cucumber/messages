#include "cucumber/messages/hook_type.hpp"
#include "nlohmann/json.hpp"
#include <iostream>
#include <string_view>
#include <unordered_map>

// Generated code by cpp.enum.hpp.erb

namespace cucumber::messages
{
    std::string_view to_string(hook_type value)
    {
        using map_type = std::unordered_map<hook_type, std::string_view>;

        static const map_type lut = {
            { hook_type::BEFORE_TEST_RUN, "BEFORE_TEST_RUN" },
            { hook_type::AFTER_TEST_RUN, "AFTER_TEST_RUN" },
            { hook_type::BEFORE_TEST_CASE, "BEFORE_TEST_CASE" },
            { hook_type::AFTER_TEST_CASE, "AFTER_TEST_CASE" },
            { hook_type::BEFORE_TEST_STEP, "BEFORE_TEST_STEP" },
            { hook_type::AFTER_TEST_STEP, "AFTER_TEST_STEP" },
        };

        return lut.at(value);
    }

    std::ostream& operator<<(std::ostream& stream, hook_type value)
    {
        stream << to_string(value);

        return stream;
    }

    void to_json(nlohmann::json& json, const hook_type& msg)
    {
        json = to_string(msg);
    }

    void from_json(const nlohmann::json& json, hook_type& msg)
    {
        static const std::unordered_map<std::string_view, hook_type> lut = {
            { "BEFORE_TEST_RUN", hook_type::BEFORE_TEST_RUN },
            { "AFTER_TEST_RUN", hook_type::AFTER_TEST_RUN },
            { "BEFORE_TEST_CASE", hook_type::BEFORE_TEST_CASE },
            { "AFTER_TEST_CASE", hook_type::AFTER_TEST_CASE },
            { "BEFORE_TEST_STEP", hook_type::BEFORE_TEST_STEP },
            { "AFTER_TEST_STEP", hook_type::AFTER_TEST_STEP },
        };

        msg = lut.at(json.get<std::string_view>());
    }
}
