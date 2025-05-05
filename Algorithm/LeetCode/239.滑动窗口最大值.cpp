/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 双向队列
        vector<int> ans;
        deque<int> q; // 存数组下标
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);

        for (int i = k; i < nums.size(); ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()])
                q.pop_back();
            q.push_back(i);
            while (q.front() < i - k + 1)
                q.pop_front();
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }

    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     // 优先队列
    //     vector<int> ans;
    //     priority_queue<pair<int, int>> q;
    //     for (int i = 0; i < k; ++i)
    //         q.emplace(nums[i], i);
    //     ans.push_back(q.top().first);

    //     for (int i = k; i < nums.size(); ++i) {
    //         q.emplace(nums[i], i);
    //         while (q.top().second < i - k + 1)
    //             q.pop();
    //         ans.push_back(q.top().first);
    //     }
    //     return ans;
    // }
};
// @lc code=end

