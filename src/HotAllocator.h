#pragma once
#include <memory>

namespace Faster{
   template<typename T>
   class HotAllocator : public std::allocator<T>{

   };
}