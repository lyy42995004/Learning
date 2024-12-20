/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0, r = 0;
        int hash[128] = {0};
        while (r < s.size())
        {
            ++hash[s[r]];
            while (hash[s[r]] > 1)
                --hash[s[l++]];
            ans = max(r - l + 1, ans);
            ++r;
        }
        return ans;
    }

    // int lengthOfLongestSubstring(string s) {
    //     int ans = 0;
    //     int l = 0, r = 0;
    //     int hash[128] = {0};
    //     while (r < s.size()) {
    //         if (hash[s[r]] == 1) { // 出现重复字符
    //             while (l < r && s[l] != s[r])
    //                 hash[s[l++]] = 0;
    //             while (l < r && s[l] == s[r])
    //                 l++;
    //         } else {
    //             hash[s[r]] = 1;
    //             ans = max(ans, r - l + 1);
    //         }
    //         r++;
    //     }
    //     return ans;
    // }
};
// @lc code=end

