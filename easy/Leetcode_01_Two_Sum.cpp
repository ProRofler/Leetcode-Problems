/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]*/

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result = {0,0};
        bool solved = false;
        for (long long int i = 0; i < nums.size(); i++)
        {
            if (!solved){
                for (long long int j = 0; j < nums.size(); j++)
                {
                    if (i==j)
                    {
                        continue;
                    }

                    else if (nums.at(i) + nums.at(j) == target)
                    {
                        result.at(0)=i;
                        result.at(1)=j;
                        solved = true;
                    }
                    
                }
            }

            else
            {
                break;
            }
            
        }

        return result;

    }
};

int main(){

    Solution result;
    std::vector<int> nums = {2,5,3,4};
    int target = 6;

    std::cout << result.twoSum(nums, target).at(0) << result.twoSum(nums, target).at(1) << '\n';

    return 0;
}