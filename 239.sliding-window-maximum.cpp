/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class SolutionPQ {
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

class SolutionDQ {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> index;
		vector<int> ans;

		for (int i = 0; i < nums.size(); i++) {
			while (!index.empty() && nums[i] > nums[index.back()])
				index.pop_back();
			index.push_back(i);

			if (i >= k - 1)
				ans.push_back(nums[index.front()]);

			if (i >= k - 1 + index.front())
				index.pop_front();
		}

		return ans;
	}
};

class Solution {
	/*
	 * Accepted
	 *  - 51/51 cases passed (265 ms)
	 *  - Your runtime beats 77.6 % of cpp submissions
	 *  - Your memory usage beats 24.08 % of cpp submissions (148.8 MB)
	 */
	SolutionPQ pq;

	/*
	 * Accepted
	 *  - 51/51 cases passed (176 ms)
	 *  - Your runtime beats 99.43 % of cpp submissions
	 *  - Your memory usage beats 89.46 % of cpp submissions (134.6 MB)
	 */
	SolutionDQ dq;
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	//	return pq.maxSlidingWindow(nums, k);
		return dq.maxSlidingWindow(nums, k);
	}
};
// @lc code=end
