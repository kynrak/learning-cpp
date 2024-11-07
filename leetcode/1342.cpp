#include <iostream>
#include <ostream>

class Solution {
public:
  int numberOfSteps(int num) {
    int step{0};
    while (num != 0) {
      if (num % 2 == 0) {
        num = num / 2;
      } else {
        num = num - 1;
      }
      step++;
    }

    return step;
  }
};

int main() {
  Solution sol;
  int n{15}; // You can change n to any integer value
  int result = sol.numberOfSteps(n);

  // Print the result as an array
  std::cout << result << std::endl;
  return 0;
}
