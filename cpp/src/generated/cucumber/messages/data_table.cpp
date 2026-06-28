
#include "cucumber/messages/data_table.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string data_table::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", rows=", rows);

        return oss.str();
    }

    void data_table::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("location"), location);
        cucumber::messages::to_json(json, camelize("rows"), rows);
    }

    void data_table::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("location"), location);
        cucumber::messages::from_json(json, camelize("rows"), rows);
    }

    std::string data_table::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const data_table& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const data_table& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, data_table& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<data_table>& msg)
    {
        msg = std::make_shared<data_table>();
        msg->from_json(json);
    }
}
