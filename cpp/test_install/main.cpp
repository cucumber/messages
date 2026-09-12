#include "cucumber/messages/PickleTableCell.hpp"

int main()
{
    cucumber::messages::PickleTableCell cell;
    cell.value = "ok";
    return cell.value == "ok" ? 0 : 1;
}
