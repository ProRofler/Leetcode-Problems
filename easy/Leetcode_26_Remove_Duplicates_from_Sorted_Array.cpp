#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int i = 1;
    int j = 1;

    while (i < nums.size()) {
      if (nums.at(i) != nums.at(i - 1)) {
        nums.at(j) = nums.at(i);
        j++;
        i++;
      } else {
        i++;
      }
    }

    return j;
  }
};
