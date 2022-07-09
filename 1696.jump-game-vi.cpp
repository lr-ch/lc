/*
 * @lc app=leetcode id=1696 lang=cpp
 *
 * [1696] Jump Game VI
 */

// @lc code=start
class Solution {
	/*
	 * Time Limit Exceeded
	 *   - 5/71 cases passed (N/A)
	 */
/*
	int dp(vector<int>& nums, int k, int index) {
		if (index > nums.size() - 1) return 0;

		int ans = INT_MIN;
		for (int i = 1; i <= k; i++)
			ans = max(ans, nums[index] + dp(nums, k, index + i));

	//	cout << index << ":" << ans << endl;
		return ans;
	}
public:
	int maxResult(vector<int>& nums, int k) {
		return dp(nums, k, 0);
	}
*/
	/*
	 * Time Limit Exceeded
	 *   - 29/71 cases passed (N/A)
	 */
/*
	vector<int> memo;
	int dp(vector<int>& nums, int k, int index) {
		if (index > nums.size() - 1) return 0;
		if (memo[index] != INT_MIN) return memo[index];

		int ans = INT_MIN;
		for (int i = 1; i <= k; i++) {
			ans = max(ans, nums[index] + dp(nums, k, index + i));
			memo[index] = ans;
		}

	//	cout << index << ":" << ans << endl;
		return ans;
	}

public:
	int maxResult(vector<int>& nums, int k) {
		memo.assign(nums.size(), INT_MIN);
		return dp(nums, k, 0);
	}
*/
public:
	int maxResult(vector<int>& nums, int k) {
		int n = nums.size();

		// <score [i...n - 1], i>
		priority_queue<pair<int, int>> pq;
		pq.push(pair<int, int>(nums[n - 1], n - 1));

		int i = n - 2, ans = nums[n - 1];
		while (i >= 0) {
		//	cout << i << " " << pq.top().second << ":" << pq.top().first << endl;

			// remove those items in pq which are beyond the range allowed to jump
			while (pq.top().second - i > k)
				pq.pop();

			// calculate current score and put it into pq,
			// the maximun score will always on the top
			int currScore = nums[i] + pq.top().first;
			pq.push(pair<int, int>(currScore, i));

			ans = currScore;
			i--;
		}

	//	return pq.top().first;	//-> pq.top().second may not be 0, a.k.a index#0
		return ans;
	}
};
// @lc code=end

