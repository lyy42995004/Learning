/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 排序 + 双指针
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            // 转化为两数之和
            int target = -nums[i];
            // 只统计nums[i] < 0的情况
            if (target < 0)
                break;
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            // 左指针从i+1开始，避免重复
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum > target) {
                    r--;
                } else if(sum < target) {
                    l++;
                } else {
                    ans.push_back({nums[i], nums[l++], nums[r--]});
                    // 去重left，right
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

