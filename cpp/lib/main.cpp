

#include "cucumber/messages/test_run_hook_started.hpp"
#include "cucumber/messages/test_step_result.hpp"
#include "cucumber/messages/utils.hpp"
#include "nlohmann/json.hpp"
#include <iostream>
#include <memory>

namespace cucumber::messages
{
    struct foo
    {
        int a;

        void to_json(nlohmann::json& json) const;
    };

    struct bar
    {
        std::shared_ptr<foo> foo_ = std::make_shared<foo>();

        void to_json(nlohmann::json& json) const;
    };

    void to_json(nlohmann::json& json, const foo& foo_)
    {
        foo_.to_json(json);
    }

    void to_json(nlohmann::json& json, const bar& bar_)
    {
        bar_.to_json(json);
    }

    void foo::to_json(nlohmann::json& json) const
    {
        json["a"] = a;
    }

    void bar::to_json(nlohmann::json& json) const
    {
        json["foo"] = foo_;
    }
}

int main()
{

    cucumber::messages::test_step_result msg{};

    std::cout << msg.to_json() << std::endl;
    std::cout << msg.to_json() << std::endl;
    std::cout << msg.to_json() << std::endl;
}
