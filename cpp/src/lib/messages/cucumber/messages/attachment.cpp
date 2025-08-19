#include <sstream>

#include <cucumber/messages/utils.hpp>
#include <cucumber/messages/attachment.hpp>

namespace cucumber::messages {

std::string
attachment::to_string() const
{
    std::ostringstream oss;

    cucumber::messages::to_string(oss, "body=", body);
    cucumber::messages::to_string(oss, ", content_encoding=", content_encoding);
    cucumber::messages::to_string(oss, ", file_name=", file_name);
    cucumber::messages::to_string(oss, ", media_type=", media_type);
    cucumber::messages::to_string(oss, ", source=", source);
    cucumber::messages::to_string(oss, ", test_case_started_id=", test_case_started_id);
    cucumber::messages::to_string(oss, ", test_step_id=", test_step_id);
    cucumber::messages::to_string(oss, ", url=", url);
    cucumber::messages::to_string(oss, ", test_run_started_id=", test_run_started_id);
    cucumber::messages::to_string(oss, ", test_run_hook_started_id=", test_run_hook_started_id);
    cucumber::messages::to_string(oss, ", timestamp=", timestamp);

    return oss.str();
}

void
attachment::to_json(json& j) const
{
    cucumber::messages::to_json(j, camelize("body"), body);
    cucumber::messages::to_json(j, camelize("content_encoding"), content_encoding);
    cucumber::messages::to_json(j, camelize("file_name"), file_name);
    cucumber::messages::to_json(j, camelize("media_type"), media_type);
    cucumber::messages::to_json(j, camelize("source"), source);
    cucumber::messages::to_json(j, camelize("test_case_started_id"), test_case_started_id);
    cucumber::messages::to_json(j, camelize("test_step_id"), test_step_id);
    cucumber::messages::to_json(j, camelize("url"), url);
    cucumber::messages::to_json(j, camelize("test_run_started_id"), test_run_started_id);
    cucumber::messages::to_json(j, camelize("test_run_hook_started_id"), test_run_hook_started_id);
    cucumber::messages::to_json(j, camelize("timestamp"), timestamp);
}

std::string
attachment::to_json() const
{
    std::ostringstream oss;
    json j;

    to_json(j);

    oss << j;

    return oss.str();
}

std::ostream&
operator<<(std::ostream& os, const attachment& msg)
{
    os << msg.to_string();

    return os;
}

void to_json(json& j, const attachment& m)
{ m.to_json(j); }

}
