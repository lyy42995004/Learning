/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int hash_s[128] = {0}, hash_t[128] = {0};
        for (auto ch : t) 
            hash_t[ch]++;
        int left = 0, right = 0;
        int minlen = INT_MAX, begin = -1;
        int count = 0;
        while (right < s.size()) {
            int chr = s[right];
            hash_s[chr]++;
            if (hash_s[chr] <= hash_t[chr])
                count++;
            while (count == t.size()) {
                int chl = s[left];
                if (minlen > right - left + 1) {
                    minlen  = right - left + 1;
                    begin = left;
                }
                if (hash_s[chl] <= hash_t[chl])
                    count--;
                hash_s[chl]--;
                left++;
            }
            right++;
        }
        return (begin == -1 ? "" : s.substr(begin, minlen));
    }
};
// @lc code=end

