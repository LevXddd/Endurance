#include <cstdlib>
#include <iostream>

void helloGuest() { std::cout << "Hello, customer: " << '\n'; }

int itsPurpose() {

  std::cout << "Enter the integer(not zero): ";
  int x{};
  std::cin >> x;
  return x;
}

int main() {

  int y{itsPurpose()};
  if (y == 0) {
    std::cout << "The process is cancelled. Try again." << '\n';
    return EXIT_FAILURE;
  } else {

    helloGuest();
    std::cout << "The processing..." << '\n';
    std::cout << "The double is: " << y * 2 << '\n';
    return EXIT_SUCCESS;
  }
}
