#include <iostream>
#include <vector>

class Solution {
public:
  int maximumWealth(std::vector<std::vector<int>> &accounts) {
    if (accounts.empty())
      return 0;
    // m x n dynamic array
    // accounts[i][j] is the amount of money ith customer has in the jth bank
    // return the wealth that the richest man has
    // double for loop over
    int richestWealth{0};
    for (int i = 0; i < accounts.size(); i++) {
      int wealth{0};

      if (accounts[i].empty())
        continue;
      for (int j = 0; j < accounts[i].size(); j++) {
        wealth += accounts[i][j];
      }

      if (wealth > richestWealth) {
        richestWealth = wealth;
      }
    }

    return richestWealth;
  }
};

int main() {
  Solution sol;
  std::vector<std::vector<int>> accounts = {{1, 2, 3}, {3, 2, 1}};
  std::cout << "Maximum wealth: " << sol.maximumWealth(accounts) << std::endl;
  return 0;
}
