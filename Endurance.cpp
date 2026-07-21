#include <cassert>  // is nessesary for assert
#include <iostream> //iostream connects output and input

int launch_option() {
  std::cout << "Write true or false if you are ready for starting: " << '\n';
  bool launch_option = false;
  std::cin >>
      launch_option; // user input, only true or false is accepted(or 1 or 0)
  if (launch_option == false)
    std::cout << "The launch is canceled" << '\n';
  else if (launch_option == true) {
    std::cout << "The launch is started" << '\n';
  }
  return 0;
  /*
  actually it's a comment(only for check)

  */

#if 0 
    int age = 0;
#endif
  [[maybe_unused]] int age = 0;
}
