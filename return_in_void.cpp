#include <iostream>
void printValue(int x, int y) {
  if (y == 0) {
    std::cout << "The process is cancelled";
    return;
  }
  std::cout << x / y << '\n';
  std::cout << "Continues safely!\n";
}

int main() {

  std::cout << "Enter the x: ";
  int x{};
  int y{};
  std::cin >> x;
  std::cout << "Enter the y: ";
  std::cin >> y;
  printValue(x, y);
  return 0;
}
