#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int i = digits.size() - 1;

    ++digits[i];
    if (i == 0 && digits[i] == 10) {
      digits[i] = 1;
      digits.push_back(0);
    }

    while (i) {
      if (digits[i] == 10) {
        digits[i] = 0;
        ++digits[i - 1];
        if (i - 1 == 0 && digits[i - 1] == 10) {
          digits[i - 1] = 1;
          digits.push_back(0);
          break;
        }
      } else {
        break;
      }
      --i;
    }

    return digits;
  }
};

int main() {
  // test
}