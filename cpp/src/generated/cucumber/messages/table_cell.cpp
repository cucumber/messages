
#include "cucumber/messages/table_cell.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string table_cell::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", value=", value);

        return oss.str();
    }

    void table_cell::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("location"), location);
        cucumber::messages::to_json(json, camelize("value"), value);
    }

    void table_cell::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("location"), location);
        cucumber::messages::from_json(json, camelize("value"), value);
    }

    std::string table_cell::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const table_cell& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const table_cell& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, table_cell& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<table_cell>& msg)
    {
        msg = std::make_shared<table_cell>();
        msg->from_json(json);
    }
}
