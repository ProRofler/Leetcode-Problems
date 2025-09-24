#include <cctype>
#include <iostream>
#include <string>

// tolower
// isalpha

using namespace std;

class Solution {
 public:
  static bool isPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
      if (!isalnum(s.at(i))) {
        i++;
        continue;
      }
      if (!isalnum(s.at(j))) {
        j--;
        continue;
      }

      if (tolower(s.at(i)) != tolower(s.at(j))) {
        return false;
      }
      i++;
      j--;
    }

    return true;
  }
};

int main() {
  //
  cout << "Is palindrome: "
       << Solution::isPalindrome("A man, a plan, a canal: Panama") << std::endl;

  return 0;
}