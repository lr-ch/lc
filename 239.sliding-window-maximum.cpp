/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		priority_queue<pair<int, int>> pq;	// (nums, index)
		vector<int> ans;

		for (int i = 0; i < k; i++)
			pq.push({ nums[i], i });

		ans.push_back(pq.top().first);
		for (int i = k; i < nums.size(); i++) {
			// keep pq.top() always hold the maximun value in the window
			while (!pq.empty() && pq.top().second <= i - k)
				pq.pop();
			pq.push({nums[i], i});
			ans.push_back(pq.top().first);
		}
		return ans;
	}
};
// @lc code=end
