/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1.排序哈希
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hash;
        for (auto s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(s);
        }
        for (auto p : hash)
            ans.push_back(p.second);
        return ans;
        // 2.计数哈希
        vector<vector<string>> ans;
        map<array<int, 26>, vector<string>> hash;
        array<int, 26> word_hash;
        for (auto s : strs) {
            word_hash.fill(0);
            for (auto& ch : s)
                word_hash[ch - 'a']++;
            hash[word_hash].push_back(s);
        }
        for (auto p : hash)
            ans.push_back(p.second);
        return ans; 
    }
};
// @lc code=end

