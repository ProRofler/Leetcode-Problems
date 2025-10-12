#include <functional>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    std::function<TreeNode*(int, int)> recursive_solution =
        [&nums, &recursive_solution](int l, int r) -> TreeNode* {
      if (l > r) return nullptr;

      int c = (l + r) / 2;
      TreeNode* root = new TreeNode(nums[c]);
      root->left = recursive_solution(l, c - 1);
      root->right = recursive_solution(c + 1, r);

      return root;
    };

    return recursive_solution(0, nums.size() - 1);
  }
};

int main() {
  //
}