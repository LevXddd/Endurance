
#include <cstdlib>
#include <iostream>

// yes you might again will say that & is not ideal, but we need to get two
// variables and the easiet the way is to use void without return, yes might
// there are other ways which will require new commands and etc and I guess they
// will be in the furute on the site and not now.

void gettingInformation(int &age, double &height) {
  std::cout << "Write your age: ";
  std::cout << "Write your height: ";
  std::cin >> age >> height;
}
// here we do not use & because we need just receive data, and we do not need to
// change this so we canw rite const in order to prevent from bugs.
// we can use return  return (age >= 14) || (height >= 140.0); || here means or
// but what if we want to use 14 age minimum AND 140 sm minimum? we will use &&

bool checkingRequirements(const int age, const double height) {
  return (age >= 14) && (height >= 140.0);
}
int main() {
  int age{};
  double height{};
  gettingInformation(age, height);
  if (checkingRequirements(age, height)) {
    std::cout << "Have fun\n";
  }
  std::cout << "You do not have access\n";
  return EXIT_SUCCESS;
}
