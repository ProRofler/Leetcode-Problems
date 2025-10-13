#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    if (s.size() < 2) return false;

    vector<char> res;
    res.reserve(100);

    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];

      if (c == '(' || c == '{' || c == '[') {
        res.push_back(c);
      } else {
        if (res.empty()) return false;
        int t = s[i] - (int)res.back();

        if (t != 1 && t != 2) {
          return false;
        }
        res.pop_back();
      }
    }

    return res.empty();
  }
};

int main() {
  string str = "()";

  Solution s;

  cout << s.isValid("()") << ' ' << s.isValid("[)") << endl;
}