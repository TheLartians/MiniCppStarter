#include <iostream>
#include <greeter.h>

int main() {
  greeter::Greeter greeter("World");
  std::cout << greeter.greet() << std::endl;
  return 0;
}
