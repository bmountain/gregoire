#ifndef KEY_VALUE_PAIR_H
#define KEY_VALUE_PAIR_H

#include <concepts>
#include <string>
#include <utility>

template <typename Key, typename Value>
  requires std::integral<Key> && std::floating_point<Value>
class KeyValuePair
{
public:
  KeyValuePair(Key key = Key{}, Value value = Value{})
  : key_(std::move(key))
  , value_(std::move(value))
  {
  }

  void setKey(Key key)
  {
    key_ = std::move(key);
  }
  Key getKey() const
  {
    return key_;
  }
  void setValue(Value value)
  {
    value_ = std::move(value);
  }
  Value getValue() const
  {
    return value_;
  }

private:
  Key key_;
  Value value_;
};

#endif /* KEY_VALUE_PAIR_H */