#include "airline.h"
#include <print>
using namespace std;

int main()
{
  AirlineTicket ticket{};
  ticket.setFrequentFlyerNumber(std::nullopt);
  std::println("Flyer Number: {}", ticket.getFrequentFlyerNumber().value_or(-1));
  ticket.setFrequentFlyerNumber(2);
  std::println("Flyer Number: {}", ticket.getFrequentFlyerNumber().value_or(-1));
}