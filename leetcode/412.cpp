#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> result(n);
    for (int i = 1; i <= n; i++) {
      if (i % 3 == 0 && i % 5 == 0) {
        result.push_back("FizzBuzz");
      } else if (i % 3 == 0) {
        result.push_back("Fizz");

      } else if (i % 5 == 0) {
        result.push_back("Buzz");
      } else {
        result.push_back(std::to_string(i));
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  int n{15}; // You can change n to any integer value
  std::vector<std::string> result = sol.fizzBuzz(n);

  // Print the result as an array
  std::cout << "[";
  for (size_t i = 0; i < result.size(); ++i) {
    std::cout << result[i];
    if (i < result.size() - 1) {
      std::cout << ", "; // Add comma for all but the last element
    }
  }
  std::cout << "]" << std::endl; // Close the array

  return 0;
}
