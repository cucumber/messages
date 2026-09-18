#include "cucumber/messages/PickleTableRow.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code by cpp.hpp.erb

namespace cucumber::messages
{
    std::string PickleTableRow::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "cells=", cells);

        return oss.str();
    }

    void PickleTableRow::to_json(nlohmann::json& json) const
    {
        cucumber::messages::to_json(json, "cells", cells);
    }

    void PickleTableRow::from_json(const nlohmann::json& json)
    {
        cucumber::messages::from_json(json, "cells", cells);
    }

    std::string PickleTableRow::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const PickleTableRow& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const PickleTableRow& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, PickleTableRow& msg)
    {
        msg.from_json(json);
    }
}
