/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> num_set;
        for (auto num : nums)
            num_set.insert(num);
        for (auto num : num_set) {
            // 判断是不是连续序列起点
            if (!num_set.count(num - 1)) {
                int cur = num;
                int count = 1;
                
                while (num_set.count(num + 1)) {
                    num++;
                    count++;
                }
                
                ans = max(count, ans);
            }
        }
        return ans;
    } 
};
// @lc code=end

