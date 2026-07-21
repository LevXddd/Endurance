#include <cstdlib>
#include <iostream>

void something() { std::cout << "Hello! Accept my congratulations" << '\n'; }

double getNumber() {
  double value{};
  std::cin >> value;
  return value;
}

int main() {
  something();
  std::cout << "Write the first number (x): ";
  double x{getNumber()};

  std::cout << "Write the second number (y): ";
  double y(getNumber());
  
  if (y == 0) {
    std::cout << "The proccess is cancelled, division on zero is unavailable";
    return EXIT_FAILURE;

  } else {
    std::cout << "The division will be " << x / y;
    return EXIT_SUCCESS;
  }
}
