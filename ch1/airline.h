#ifndef AIRLINE__H
#define AIRLINE__H
#include <optional>
#include <string>

class AirlineTicket
{
public:
  AirlineTicket() = default;
  ~AirlineTicket() = default;

  double calculatePriceInDollars() const;

  std::string getPassengerName() const;
  void setPassengerName(const std::string&);

  int getNumberOfMiles() const;
  void setNumberOfMiles(int&);

  bool hasEliteSuperRewardStatus() const;
  void setHasEliteSuperRewardStatus(bool);

  std::optional<int> getFrequentFlyerNumber() const;
  void setFrequentFlyerNumber(std::optional<int>);

private:
  std::string mPassengerName{};
  int mNumberOfMiles{};
  bool mHasEliteSuperRewardStatus{false};
  std::optional<int> mFrequentFlyerNumber{std::nullopt};
};

#endif /* AIRLINE__H */