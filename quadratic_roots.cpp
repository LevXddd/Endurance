#include <cmath>
#include <cstdlib>
#include <iostream>
#include <print>

namespace {
double a{};
double b{};
double c{};
} // namespace

void gettingInput() {
  std::print("Enter coefficients(a, b, c): ");
  std::cin >> a >> b >> c;
}

bool checking() {
  while (a == 0) {

    std::print("It's a linear function! Rewrite the a: ");
    std::cin >> a;
  }
  return true;
}
double calculating() {
  using std::print;
  double formulaDiscriminant{pow(b, 2) - (4 * a * c)};

  print("The discriminant is: {}\n", formulaDiscriminant);
  if (formulaDiscriminant < 0) {
    print("There are not solutions.\n");
    return EXIT_SUCCESS;
  }
  double theFirstRoot{(-b + sqrt(formulaDiscriminant)) / (2 * a)};
  double theSecondRoot{(-b - sqrt(formulaDiscriminant)) / (2 * a)};

  if (formulaDiscriminant == 0) {
    print("There is exactly one solution: {}\n", theFirstRoot);
    return EXIT_SUCCESS;
  }
  print("There are two solutions: {} and {}\n", theFirstRoot, theSecondRoot);
  return EXIT_SUCCESS;
}
int main() {
  gettingInput();
  checking();
  calculating();
  return EXIT_SUCCESS;
}
