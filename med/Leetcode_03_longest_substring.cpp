#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {

  string m_substr;
  string t_substr;

  for (auto c : s) {
    auto p = t_substr.find(c);
    if (p == t_substr.npos) {  // IF NOT FOUND
      t_substr.push_back(c);
      if (t_substr.size() > m_substr.size()) {
        m_substr = t_substr;
      }
    } else {  // IF FOUND
      t_substr.erase(0, p+1);
      t_substr.push_back(c);
    }
    cout << t_substr << '\n';
  }
  return m_substr.size();
}

int lengthOfLongestSubstring_sliding_window(string s) {
  unordered_set<char> chars;

  size_t start = 0;
  size_t end = 0;

  size_t _max = 0;

 while(end < s.length()) {
    if (chars.find(s.at(end)) == chars.end()) {
      chars.emplace(s.at(end));
      _max = max(_max, (end - start) + 1);
      end++;
    } else {
      chars.erase(s.at(start));
      start++;
    }
  }

  return _max;
}


int main() {
  cout << lengthOfLongestSubstring("aa") << " : result\n";

  return 0;
}