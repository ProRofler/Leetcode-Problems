#include <iostream>

using namespace std;

// not used at the moment
bool is_palindrome(const string& s) {
  auto start = 0ull;
  auto end = s.size() - 1ull;

  while (start < end) {
    if (s.at(start) != s.at(end)) return false;
    start++;
    end--;
  }
  return true;
}

string iterate_pal(int left, int right, const string& s) {
  while (left >= 0 && right < s.size() && s[left] == s[right]) {
    left--;
    right++;
  }
  return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
  string longest = "";

  for (int i = 0; i < s.size(); i++) {
    auto oddpal = iterate_pal(i, i, s);
    auto evenpal = iterate_pal(i, i + 1, s);

    if (oddpal.size() > longest.size()) longest = oddpal;
    if (evenpal.size() > longest.size()) longest = oddpal;
  }

  return longest;
}

int main() {
  cout << longestPalindrome("kekarrasky") << endl;

  return 0;
}