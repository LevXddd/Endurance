#include <cstdlib>
#include <iostream>
void functionONE() { std::cout << "The process of buying is started... "; }
namespace Adidas {
void Swift() {
  std::cout << "Adidas Swift Model: Lightweight everyday comfort.\n";
}
} // namespace Adidas
namespace Nike {
void Swift() {
  std::cout << "Nike Swift Model: Built for speed and support.\n ";
}
} // namespace Nike

int main() {
  functionONE();
  Adidas::Swift();
  Nike::Swift();
  return EXIT_SUCCESS;
}
