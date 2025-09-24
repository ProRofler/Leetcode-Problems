#include <iostream>

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    size_t temp = 0;  // it might overflow on int
    int original = x;
    // std::cout << x << " : " << temp << std::endl;

    while (x) {
      x < 10 ? temp = (temp * 10) + x : temp = (temp * 10) + (x % 10);
      x /= 10;

      // std::cout << x << " : " << temp << std::endl;
    }

    return original == temp;
  }

  bool isPalindrome_effective(
      int x) {  // it was done after checking the solution
    if (x < 0) return false;
    long temp = 0;
    int original = x;

    while (x) {
      temp = temp * 10 + x % 10;
      x /= 10;
    }

    return original == temp;
  }
};

int main() {
  Solution s;

  for (int i = 0; i != 100; ++i) {
    std::cout << s.isPalindrome(rand() % 100000) << std::endl;
  }
}