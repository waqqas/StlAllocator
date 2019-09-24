#include <vector>
#include "HotAllocator.h"

int main(void)
{
  std::vector<int32_t, Faster::HotAllocator<int32_t>> v1;
  for(int32_t count = 0; count < 10000; count++)
  {
    v1.push_back(count);
  }

  return 0;
}