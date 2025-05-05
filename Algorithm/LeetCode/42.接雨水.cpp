/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // 1.双指针解法1
        int l = 0, r = 0;
        while (l < height.size() && height[l] == 0)
            l++;
        r = l + 1;

        int ans = 0;
        int tmp = 0; // 记录区间多余块
        while (r < height.size()) {
            if (height[r] >= height[l]) { // 更新左边界，记录区间储水量
                ans += (r - l - 1) * min(height[r], height[l]);
                ans -= tmp;
                tmp = 0;
                l = r;
            } else {
                tmp += height[r];
            }
            r++;
        }
        // 最后一个部分没算上
        if (l != r) {
            int l_last = l;
            r = height.size() - 1;
            while (r >= 0 && height[r] == 0)
                r--;
            l = r - 1;

            tmp = 0;
            while (l >= l_last) {
                if (height[l] >= height[r]) {
                    ans += (r - l - 1) * min(height[r], height[l]);
                    ans -= tmp;
                    tmp = 0;
                    r = l;
                } else {
                    tmp += height[l];
                }
                l--;                
            }
        }
        return ans;


        // 2.双指针解法2
        int ans = 0;
        int l = 0, r = height.size() - 1;
        int l_max = 0, r_max = 0;

        while (l < r) {
            l_max = max(height[l], l_max);
            r_max = max(height[r], r_max);

            if (height[l] < height[r]) {
                ans += l_max - height[l];
                l++;
            } else {
                ans += r_max - height[r];
                r--;
            }
        }

        return ans;
    }
};
// @lc code=end

