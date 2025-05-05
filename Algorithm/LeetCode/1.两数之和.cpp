/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 1.枚举所有情况 O(n^2)
        vector<int> ans;
        for (int i  = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        } 
        return {};
        // 2.哈希表 O(n)
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hash.find(target - nums[i]);
            if (it != hash.end())
                return {i, it->second};
            hash[nums[i]] = i; // 插入哈希表
        }
        return {};
    }
};
// @lc code=end

