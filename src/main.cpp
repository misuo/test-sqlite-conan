#include <iostream>
#include <sqlite3.h>

int main()
{
  std::cout << "Hello World!" << std::endl;
  std::cout << sqlite3_libversion() << std::endl;

  return 0; // Success
}