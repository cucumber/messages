
#include "cucumber/messages/pickle_step_argument.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string pickle_step_argument::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "doc_string=", doc_string);
        cucumber::messages::to_string(oss, ", data_table=", data_table);

        return oss.str();
    }

    void pickle_step_argument::to_json(nlohmann::json& json) const
    {
        if (doc_string.has_value())
        {
            json[camelize("doc_string")] = doc_string;
        }
        if (data_table.has_value())
        {
            json[camelize("data_table")] = data_table;
        }
    }

    void pickle_step_argument::from_json(const nlohmann::json& json)
    {
        if (doc_string.has_value())
        {
            json.at(camelize("doc_string")).get_to(doc_string.emplace());
        }
        if (data_table.has_value())
        {
            json.at(camelize("data_table")).get_to(data_table.emplace());
        }
    }

    std::string pickle_step_argument::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const pickle_step_argument& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const pickle_step_argument& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, pickle_step_argument& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<pickle_step_argument>& msg)
    {
        msg = std::make_shared<pickle_step_argument>();
        msg->from_json(json);
    }
}
