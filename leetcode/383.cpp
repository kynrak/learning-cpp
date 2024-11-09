#include <iostream>
#include <string>
#include <unordered_map>

bool canConstruct(const std::string &ransomNote, const std::string &magazine) {
  std::unordered_map<char, int> magazineCount;

  // Count the frequency of each character in magazine
  for (char ch : magazine) {
    magazineCount[ch]++;
  }

  // Check if we can construct ransomNote
  for (char ch : ransomNote) {
    if (magazineCount[ch] == 0) {
      // If the character is not available or used up, return false
      return false;
    }
    magazineCount[ch]--; // Use up one occurrence of this character
  }

  return true;
}

int main() {
  std::string ransomNote = "aa";
  std::string magazine = "aab";

  if (canConstruct(ransomNote, magazine)) {
    std::cout << "Yes, the ransom note can be constructed." << std::endl;
  } else {
    std::cout << "No, the ransom note cannot be constructed." << std::endl;
  }

  return 0;
}
