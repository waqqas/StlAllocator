#pragma once
#include <unordered_map>

template<class T>
class SecurityHasher
{
public:
  SecurityHasher(){}
  size_t operator()(T key) const noexcept
  {
    return static_cast<size_t>(key);
  }
};

using security_map = std::unordered_map<int32_t, uint64_t, SecurityHasher<int32_t> >;
