#include "HotAllocator.h"

#include <iostream>
#include <type_traits>
#include <vector>

template <bool enablePadding = false>
struct Header
{
  void print(){
    std::cout << a << " " << b << std::endl;
  }

  Header()
    : a(0)
    , b(1)
  {}
  uint16_t a;
  uint16_t b;
};

#pragma pack(1)

template <>
struct Header<true>
{
  void print(){
    std::cout << a << " " << b << std::endl;
  }
  Header()
    : a(2)
    , b(3)
  {}
  uint16_t a;
  uint8_t  padding[5];
  uint16_t b;
};

#pragma pack(4)

int main(void)
{
  // std::vector<int32_t, Faster::HotAllocator<int32_t>> v1;
  // for(int32_t count = 0; count < 10; count++)
  // {
  //   v1.push_back(count);
  // }

  // while(v1.size()> 0)
  // {
  //   std::cout << v1.back() << std::endl;
  //   v1.pop_back();
  // }
  Header<> a;
  std::cout << "size of foo: " << sizeof(a) << std::endl;
  a.print();

  Header<true> b;
  std::cout << "size of foo: " << sizeof(b) << std::endl;
  b.print();

  return 0;
}