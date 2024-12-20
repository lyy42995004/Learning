/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int count = 0; // 每有一个相同的加一，不同的减一
        int l = 0, r = 0;
        int hash[26] = {0};

        int hash_p[26] = {0};
        for (auto ch : p)
            hash_p[ch - 'a']++;
        
        while (r < s.size()) {
            int index = s[r] - 'a';
            if (++hash[index] <= hash_p[index])
                count++;
            if (r - l + 1 > p.size()) {
                if (hash[s[l] - 'a']-- <= hash_p[s[l] - 'a'])
                    count--;
                l++;
            }
            if (count == p.size())
                ans.push_back(l);
            r++;
        }
        return ans; 
    }
};
// @lc code=end

