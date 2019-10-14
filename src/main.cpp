#include "SecurityHasher.h"

#include <iostream>

int main(void)
{
  security_map map;
  map[1] = 1;
  map[2] = 2;

  for (const auto &item : map)
  {
    std::cout << "Key:[" << item.first << "] Value:[" << item.second << "]\n";
  }

  std::cout << "bucket count: " << map.bucket_count() << std::endl;
  for (security_map::size_type bucket_number = 0; bucket_number < map.bucket_count();
       ++bucket_number)
  {
    std::cout << "bucket: " << bucket_number << " size: " << map.bucket_size(bucket_number)
              << std::endl;
  }
  return 0;
}
