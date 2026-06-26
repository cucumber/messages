
#include "cucumber/messages/pickle_table_row.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string pickle_table_row::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "cells=", cells);

        return oss.str();
    }

    void pickle_table_row::to_json(nlohmann::json& json) const
    {
        json[camelize("cells")] = cells;
    }

    void pickle_table_row::from_json(const nlohmann::json& json)
    {
        json.at(camelize("cells")).get_to(cells);
    }

    std::string pickle_table_row::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const pickle_table_row& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const pickle_table_row& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, pickle_table_row& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<pickle_table_row>& msg)
    {
        msg = std::make_shared<pickle_table_row>();
        msg->from_json(json);
    }
}
