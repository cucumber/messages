
#include "cucumber/messages/step.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <ostream>
#include <sstream>
#include <string>

// Generated code

namespace cucumber::messages
{
    std::string step::to_string() const
    {
        std::ostringstream oss;

        cucumber::messages::to_string(oss, "location=", location);
        cucumber::messages::to_string(oss, ", keyword=", keyword);
        cucumber::messages::to_string(oss, ", keyword_type=", keyword_type);
        cucumber::messages::to_string(oss, ", text=", text);
        cucumber::messages::to_string(oss, ", doc_string=", doc_string);
        cucumber::messages::to_string(oss, ", data_table=", data_table);
        cucumber::messages::to_string(oss, ", id=", id);

        return oss.str();
    }

    void step::to_json(nlohmann::json& json) const
    {
        json[camelize("location")] = location;
        json[camelize("keyword")] = keyword;
        if (keyword_type.has_value())
        {
            json[camelize("keyword_type")] = keyword_type;
        }
        json[camelize("text")] = text;
        if (doc_string.has_value())
        {
            json[camelize("doc_string")] = doc_string;
        }
        if (data_table.has_value())
        {
            json[camelize("data_table")] = data_table;
        }
        json[camelize("id")] = id;
    }

    void step::from_json(const nlohmann::json& json)
    {
        json.at(camelize("location")).get_to(location);
        json.at(camelize("keyword")).get_to(keyword);
        if (keyword_type.has_value())
        {
            json.at(camelize("keyword_type")).get_to(keyword_type.emplace());
        }
        json.at(camelize("text")).get_to(text);
        if (doc_string.has_value())
        {
            json.at(camelize("doc_string")).get_to(doc_string.emplace());
        }
        if (data_table.has_value())
        {
            json.at(camelize("data_table")).get_to(data_table.emplace());
        }
        json.at(camelize("id")).get_to(id);
    }

    std::string step::to_json() const
    {
        nlohmann::json json;

        to_json(json);

        return json.dump();
    }

    std::ostream& operator<<(std::ostream& ostream, const step& msg)
    {
        ostream << msg.to_string();

        return ostream;
    }

    void to_json(nlohmann::json& json, const step& msg)
    {
        msg.to_json(json);
    }

    void from_json(const nlohmann::json& json, step& msg)
    {
        msg.from_json(json);
    }

    void from_json(const nlohmann::json& json, std::shared_ptr<step>& msg)
    {
        msg = std::make_shared<step>();
        msg->from_json(json);
    }
}
