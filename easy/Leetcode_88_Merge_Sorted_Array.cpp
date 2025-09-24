#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m + n - 1;

    while (m > 0 && n > 0) {
      if (nums1.at(m - 1) > nums2.at(n - 1)) {
        nums1.at(i) = nums1.at(m - 1);
        m--;
      } else {
        nums1.at(i) = nums2.at(n - 1);
        n--;
      }
      i--;
    }

    while (n > 0) {
      nums1.at(i) = nums2.at(n - 1);
      n--;
      i--;
    }
  }
};

int main() { return 1; }