#include "cucumber/messages/envelope.hpp"
#include "cucumber/messages/meta.hpp"
#include <iostream>

int main()
{
    cucumber::messages::envelope env;
    env.meta = cucumber::messages::meta{};
    std::cout << env.to_json() << "\n";
}
