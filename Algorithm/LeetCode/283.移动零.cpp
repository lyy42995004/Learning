/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // l维持一个非零数组区间
        int l = 0, r = 0;
        while (r < nums.size()) {
            if (nums[r] != 0) 
                swap(nums[l++], nums[r]);
            r++;
        }
    }
};
// @lc code=end

