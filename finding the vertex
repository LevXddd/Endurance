
#include "exc.h"
#include <cstdlib>
#include <iostream>

int main() {
  double a{};
  double b{};
  functionPretty(a, b);
  functionCalculating(a, b);
  return EXIT_SUCCESS;
}

void functionPretty(double &a, double &b) {
  std::cout << "Write the next coefficients(a and b): ";
  std::cin >> a >> b;
}
int functionCalculating(double a, double b) {
  if (a == 0) {
    std::cout << "The process is aborted, divizion on zero is impossible"
              << '\n';
    return EXIT_FAILURE;
  } else {
    double z{(-b) / (2 * a)};
    std::cout << z;
    return EXIT_SUCCESS;
  }
}

