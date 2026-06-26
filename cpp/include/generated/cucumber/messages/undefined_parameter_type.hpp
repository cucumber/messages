#ifndef CUCUMBER_MESSAGES_UNDEFINED_PARAMETER_TYPE_HPP
#define CUCUMBER_MESSAGES_UNDEFINED_PARAMETER_TYPE_HPP

#include "nlohmann/json_fwd.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>

namespace cucumber::messages
{
    //
    // Represents the UndefinedParameterType message in Cucumber's message protocol
    // @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
    //
    // Generated code

    struct undefined_parameter_type
    {
        using shared_ptr = undefined_parameter_type;//std::shared_ptr<undefined_parameter_type>;

        std::string expression;
        std::string name;

        [[nodiscard]] std::string to_string() const;

        void to_json(nlohmann::json& json) const;
        void from_json(const nlohmann::json& json);

        [[nodiscard]] std::string to_json() const;
    };

    std::ostream& operator<<(std::ostream& ostream, const undefined_parameter_type& msg);

    void to_json(nlohmann::json& json, const undefined_parameter_type& msg);
    void from_json(const nlohmann::json& json, undefined_parameter_type& msg);
    void from_json(const nlohmann::json& json, std::shared_ptr<undefined_parameter_type>& msg);

}

#endif
