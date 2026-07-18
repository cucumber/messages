#include "cucumber/messages/Envelope.hpp"
#include "cucumber/messages/Meta.hpp"
#include <iostream>
#include <memory>

int main()
{
    cucumber::messages::Envelope env;
    env.meta = std::make_shared<cucumber::messages::Meta>();
    std::cout << env.to_json() << "\n";
}
