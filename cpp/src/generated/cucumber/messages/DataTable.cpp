#include "cucumber/messages/DataTable.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string DataTable::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", rows=", rows);

        return oss.str();
    }

    void DataTable::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "location", location);
        cucumber::messages::to_json(json, "rows", rows);
    }

    void DataTable::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "location", location);
        cucumber::messages::from_json(json, "rows", rows);
    }

    std::string DataTable::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const DataTable& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const DataTable& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, DataTable& msg)
    {
        msg.from_json(json);
    }
}
