#include <iostream>
#include <optional>
#include <string>
#include <vector>

/*
 * cpp function structure
 *
 * return_type function_name(param1_type param1, params2_type param2) {
 *  // business logic here
 *  return value;
 * }
 */

// The structure of the returned value from binary search
struct BinarySearchResult {
  int position;
  int steps;
};

/*
 * Does a binary search based on a sorted list to search for a single item
 * Returns both the position and the number of steps it took to search
 *
 * @param list A sorted array to search through
 * @param item The target item to be searched for within the array
 * @return The number of steps it takes to search for the item in the list
 */
std::optional<BinarySearchResult>
BinarySearch(const std::vector<std::string> &list, std::string item) {
  // imagine starting from the start and the end of the array
  int low{0};
  int high = list.size() - 1;
  int steps{0};

  while (low <= high) {
    // increment the steps as we enter the next iteration
    steps++;

    int mid = (low + high) / 2;
    std::string guess = list[mid];

    if (guess == item) {
      return BinarySearchResult{mid, steps};
    }

    if (guess > item) {
      // case where target is lower, set the new high
      high = mid - 1;
    } else {
      // case where target is higher, set the new low
      low = mid + 1;
    }
  }

  return std::nullopt;
}

int main() {
  std::vector<std::string> list = {"apple", "banana", "cherry",
                                   "date",  "fig",    "grape"};
  std::optional<BinarySearchResult> result = BinarySearch(list, "orange");
  std::optional<BinarySearchResult> result2 = BinarySearch(list, "banana");

  if (result) {
    std::cout << "Item found at index: " << result->position << " in "
              << result->steps << " steps.\n";
  } else {
    std::cout << "Item not found.\n";
  }

  if (result2) {
    std::cout << "Item found at index: " << result2->position << " in "
              << result2->steps << " steps.\n";
  } else {
    std::cout << "Item not found.\n";
  }

  return 0;
}
