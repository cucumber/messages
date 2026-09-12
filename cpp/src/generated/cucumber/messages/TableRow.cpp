#include "cucumber/messages/TableRow.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string TableRow::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", cells=", cells);
        cucumber::messages::to_string(oss, ", id=", id);

        return oss.str();
    }

    void TableRow::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "location", location);
        cucumber::messages::to_json(json, "cells", cells);
        cucumber::messages::to_json(json, "id", id);
    }

    void TableRow::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "location", location);
        cucumber::messages::from_json(json, "cells", cells);
        cucumber::messages::from_json(json, "id", id);
    }

    std::string TableRow::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const TableRow& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const TableRow& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, TableRow& msg)
    {
        msg.from_json(json);
    }
}
