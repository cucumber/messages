#ifndef CUCUMBER_MESSAGES_PARAMETER_TYPE_HPP
#define CUCUMBER_MESSAGES_PARAMETER_TYPE_HPP

#include "cucumber/messages/SourceReference.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    //
    // Represents the ParameterType message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct ParameterType
    {
        std::string name;
        std::vector<std::string> regularExpressions;
        bool preferForRegularExpressionMatch;
        bool useForSnippets;
        std::string id;
        std::optional<std::shared_ptr<SourceReference>> sourceReference;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const ParameterType& msg);

    void to_json(nlohmann::json& json, const ParameterType& msg);
    void from_json(const nlohmann::json& json, ParameterType& msg);
}

#endif
