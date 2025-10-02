#include "airline.h"

double AirlineTicket::calculatePriceInDollars() const
{
  return getNumberOfMiles() * 10;
}

std::string AirlineTicket::getPassengerName() const
{
  return mPassengerName;
}

void AirlineTicket::setPassengerName(const std::string& name)
{
  mPassengerName = name;
}

int AirlineTicket::getNumberOfMiles() const
{
  return mNumberOfMiles;
}

void AirlineTicket::setNumberOfMiles(int& miles)
{
  mNumberOfMiles = miles;
}

bool AirlineTicket::hasEliteSuperRewardStatus() const
{
  return mHasEliteSuperRewardStatus;
}

void AirlineTicket::setHasEliteSuperRewardStatus(bool status)
{
  mHasEliteSuperRewardStatus = status;
}

std::optional<int> AirlineTicket::getFrequentFlyerNumber() const
{
  return mFrequentFlyerNumber;
}

void AirlineTicket::setFrequentFlyerNumber(std::optional<int> number)
{
  mFrequentFlyerNumber = number;
}
