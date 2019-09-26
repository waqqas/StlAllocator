#include "HotAllocator.h"

#include <iostream>
#include <type_traits>
#include <vector>

template <typename H>
struct BaseHeader
{
  void print_header()
  {
    H *header = static_cast<H *>(this);
    std::cout << "a: " << header->a << std::endl;
    std::cout << "b: " << header->b << std::endl;
  }
};

template <bool enablePadding = false>
struct GrpHeader : BaseHeader<GrpHeader<enablePadding>>
{
  GrpHeader()
    : a(0)
    , b('0')
  {}
  uint16_t a;
  uint8_t b;
};

#pragma pack(push, 1)

template <>
struct GrpHeader<true> : BaseHeader<GrpHeader<true>>
{
  GrpHeader()
    : a(1)
    , b('1')
  {}
  uint16_t a;
  uint8_t  padding[5];
  uint8_t b;
};

#pragma pack(pop)

int main(void)
{

  GrpHeader<> a;
  std::cout << "size of foo: " << sizeof(a) << std::endl;
  a.print_header();

  GrpHeader<true> b;
  std::cout << "size of foo: " << sizeof(b) << std::endl;
  b.print_header();

  return 0;
}