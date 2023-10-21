/*
 * @lc app=leetcode id=1425 lang=cpp
 *
 * [1425] Constrained Subsequence Sum
 */

// @lc code=start
class Solution {
	template <typename T>
	struct MonotonicQueue {
		void push(T e) {
			while (!q.empty() && e >= q.back()) q.pop_back();
			q.push_back(e);
		}

		T max() { return q.front(); }

		void pop() { q.pop_front(); }

		size_t size() { return q.size(); }

		bool empty() { return q.empty(); }

	private:
		deque<T> q;
	};

public:
	int constrainedSubsetSum(vector<int>& nums, int k) {
		MonotonicQueue<pair<int, int>> mq;	// (sum, index)

		int ans = INT_MIN;
		for (int i = 0; i < nums.size(); i++) {
			// is the queue full?
			if (i > k && !mq.empty() && mq.max().second == i - k - 1)
				mq.pop();

			int sum;
			if (i == 0 || mq.empty())
				sum = nums[i];
			else
				sum = max(mq.max().first, 0) + nums[i];

			mq.push({ sum, i });
			ans = max(ans, sum);
		}

		return ans;
	}
};
// @lc code=end
