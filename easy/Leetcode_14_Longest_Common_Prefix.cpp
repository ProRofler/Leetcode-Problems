#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string res = "";

    for (int i = 0; i < strs[0].size(); ++i) {
      for (auto& str : strs) {
        if (str.size() <= i) return res;
        if (str.at(i) != strs[0][i]) return res;
      }
      res.push_back(strs[0][i]);
    }
    return res;
  }
};

int main() {
  //
}

/*

Write a function to find the longest common prefix string amongst an array of
strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.


*/