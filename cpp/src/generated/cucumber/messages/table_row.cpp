
#include "cucumber/messages/table_row.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string table_row::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", cells=", cells);
        cucumber::messages::to_string(oss, ", id=", id);

        return oss.str();
    }

    void table_row::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, camelize("location"), location);
        cucumber::messages::to_json(json, camelize("cells"), cells);
        cucumber::messages::to_json(json, camelize("id"), id);
    }

    void table_row::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, camelize("location"), location);
        cucumber::messages::from_json(json, camelize("cells"), cells);
        cucumber::messages::from_json(json, camelize("id"), id);
    }

    std::string table_row::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const table_row& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const table_row& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, table_row& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<table_row>& msg)
    {
        msg = std::make_shared<table_row>();
        msg->from_json(json);
    }
}
