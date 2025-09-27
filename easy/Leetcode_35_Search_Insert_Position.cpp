#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    int mid;

    while (l <= r) {
      mid = (l + r) / 2;
      if (nums[mid] == target) return mid;
      target > nums[mid] ? l = mid + 1 : r = mid - 1;
    }

    return nums[mid] < target ? ++mid : mid;
  }
};

int main() {
  vector<int> v{1, 3, 5, 7, 8, 9};
  Solution s;

  std::cout << s.searchInsert(v, 5) << ' ' << s.searchInsert(v, 6) << std::endl;
}

/*
Given a sorted array of distinct integers and a target value, return the index
if the target is found. If not, return the index where it would be if it were
inserted in order.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4


Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/