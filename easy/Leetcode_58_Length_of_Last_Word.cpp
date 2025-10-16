#include <string>

using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    bool started = false;
    int length = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == ' ' && started) {
        break;
      }

      if (s[i] != ' ' && started) {
        ++length;
      }

      if (s[i] != ' ' && !started) {
        started = true;
        ++length;
      }
    }
    return length;
  }
};

int main() {}