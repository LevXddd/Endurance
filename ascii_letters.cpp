#include <cstdlib>
#include <iostream>

int main(){
  char myChar('a');
  while (myChar <= 'z'){
    std::cout << myChar << ' ' << static_cast<int>(myChar) << '\n';
    myChar++; // here it's preffered to use ++myChar because it's more optimizsed
   }
   return EXIT_SUCCESS;
}
