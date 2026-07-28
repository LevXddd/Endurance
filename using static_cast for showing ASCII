#include <cstdlib>
#include <iostream>

void hello() { std::cout << "Enter a single character: "; }

char getInput() {
  char ch{};
  std::cin >> ch;
  return ch;
}
void function(const char ch) {
  int x = ch;
  // int x{ch}; or int x(ch); also work — char->int is a widening (safe) conversion
  // For explicit conversion instead, use: int x = (int)ch; or static_cast<int>(ch);
  std::cout << "You entered: " << ch << " , which ASCII code is: " << x << '\n';
}
int main() {
  hello();
  char ch{getInput()};
  function(ch);
  return EXIT_SUCCESS;
}

//Actually here was a one mistake connected to calling twice.
getInput();
char ch{getInput()};
getInput() is called twice. The first call reads real input from the buffer and discards it (unused). 
The second call reads the next token, not the same one. Just remember: 
you should only call the function once when you want to transfer its data into a variable/identifier.
