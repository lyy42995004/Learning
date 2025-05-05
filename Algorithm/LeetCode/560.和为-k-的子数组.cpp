/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (hash.count(sum - k))
                ans += hash[sum - k];
            hash[sum]++;
        }
        return ans; 
    }
};
// @lc code=end

