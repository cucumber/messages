#include "cucumber/messages/Meta.hpp"
#include "cucumber/messages/envelope.hpp"
#include <iostream>
#include <memory>

int main()
{
    cucumber::messages::envelope env;
    env.meta = std::make_shared<cucumber::messages::Meta>();
    std::cout << env.to_json() << "\n";
}
