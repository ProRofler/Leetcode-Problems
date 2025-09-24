class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    vector<int> _nums;

    for (auto& value : nums) {
      if (value != val) {
        _nums.push_back(value);
      }
    }

    nums = _nums;
    return nums.size();
  }
};

// no second vector option
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int j = 0;

        for(auto i = 0; i < nums.size(); i++){
            if(nums.at(i) != val){
                nums.at(j) = nums.at(i);
                j++;
            }
        }

    return j;

    }
};