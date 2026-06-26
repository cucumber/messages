
#include "cucumber/messages/pickle_table_cell.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string pickle_table_cell::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "value=", value);

        return oss.str();
    }

    void pickle_table_cell::to_json(nlohmann::json& json) const
    {
        json[camelize("value")] = value;
    }

    void pickle_table_cell::from_json(const nlohmann::json& json)
    {
        json.at(camelize("value")).get_to(value);
    }

    std::string pickle_table_cell::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const pickle_table_cell& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const pickle_table_cell& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, pickle_table_cell& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<pickle_table_cell>& msg)
    {
        msg = std::make_shared<pickle_table_cell>();
        msg->from_json(json);
    }
}
