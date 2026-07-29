#include <cstdlib>
#include <iostream>
#include <string>

void hello() { std::cout << "Welcome to the program!\n"; }
int writing(std::string &x, int &y) { // firsty I wrote void and it was logical, but if we want to
                                      // prevent from zeros we need to write int for returning.
  std::cout << "Write your age: ";
  std::cin >> y;
  if (y <= 0) {
    std::cout << "The program is stopped!";
    return EXIT_FAILURE;
  } // here I had one problem, when I wrote 0 it also required writing full
  // name, however, I just moved it above x so it's okay
  std::cout << "Write your full name: ";
  std::getline(std::cin >> std::ws, x);
  return EXIT_SUCCESS;
}

int gettingInput(std::string x, int y) {
  int z{static_cast<int>(x.length()) + y};
  // casting length()'s unsigned type into int (signed), so it matches y's type

  std::cout << "The sum will be " << z;
  return z;
}
int main() {
  hello();
  std::string x{};
  int y{};
  if (writing(x, y) == EXIT_FAILURE) {
    return EXIT_FAILURE;
  }
  gettingInput(x, y);
  return EXIT_SUCCESS;
}
