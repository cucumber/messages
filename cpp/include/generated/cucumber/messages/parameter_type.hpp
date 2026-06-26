#ifndef CUCUMBER_MESSAGES_PARAMETER_TYPE_HPP
#define CUCUMBER_MESSAGES_PARAMETER_TYPE_HPP

#include "cucumber/messages/source_reference.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

namespace cucumber::messages
{
    //
    // Represents the ParameterType message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct parameter_type
    {
        using shared_ptr = parameter_type;//std::shared_ptr<parameter_type>;

        std::string name;
        std::vector<std::string> regular_expressions;
        bool prefer_for_regular_expression_match;
        bool use_for_snippets;
        std::string id;
        std::optional<cucumber::messages::source_reference::shared_ptr> source_reference;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const parameter_type& msg);

    void to_json(nlohmann::json& json, const parameter_type& msg);
    void from_json(const nlohmann::json& json, parameter_type& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<parameter_type>& msg);

}

#endif
