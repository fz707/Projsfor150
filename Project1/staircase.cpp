
#include <iostream>

int main();

int main() {
  double x{};

  std::cout << "Enter value of x: ";
  std::cin >> x;

  // This local variable should hold the result of stair( x )
  int stair{};
    if (stair<x){
        while (stair<=x-1) {
            ++stair;
         }
    }
    else{
        while (stair>x){
            --stair;
        }
        
    }
  // TASK: write code that calculates an integer value
  // corresponding to the value of the function stair( x ) here

  std::cout << "The value of stair(x) is: ";
  std::cout << stair;
  std::cout << std::endl;

  return 0;
}
